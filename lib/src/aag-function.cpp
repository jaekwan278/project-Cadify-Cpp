#include "aag-function.h"

AAGAnalyzer::AAGAnalyzer(const std::vector<TopoDS_Face> &faces)
{
     int faceIndex = 0;
     for (const TopoDS_Face &face : faces)
     {
          AAGNode node;
          node.face = face;
          node.surfaceType = getSurfaceType(face);
          AAG[faceIndex] = node;
          faceIndex++;
     }
     std::cout << AAG.size() << std::endl;

     analyzeShape(AAG);

     std::cout << AAG[0].adjacentFaces.size() << std::endl;
}

std::string AAGAnalyzer::getSurfaceType(const TopoDS_Face &face) const
{
     BRepAdaptor_Surface surface(face);
     GeomAbs_SurfaceType surfaceType = surface.GetType();

     switch (surfaceType)
     {
     case GeomAbs_Plane:
          return "PLANE";
     case GeomAbs_Cylinder:
          return "CYLINDER";
     case GeomAbs_Sphere:
          return "SPHERE";
     case GeomAbs_Torus:
          return "TORUS";
     default:
          return "UNKNOWN";
     }
}

void AAGAnalyzer::analyzeShape(std::map<int, AAGNode>& baseMap){
     
     TopExp_Explorer edgeExplorer;
     
     for(auto& node : baseMap){
          const int& index = node.first;
          AAGNode& value = node.second;

          for(edgeExplorer.Init(value.face, TopAbs_EDGE); edgeExplorer.More(); edgeExplorer.Next()){
               const TopoDS_Edge& edge = TopoDS::Edge(edgeExplorer.Current());

               for(auto& adjNode : baseMap){
                    if(adjNode.first == index) continue;
                    const int& compareIndex = adjNode.first;
                    AAGNode& compareNode = adjNode.second;
                    
                    TopExp_Explorer adjEdgeExplorer(compareNode.face, TopAbs_EDGE);
                    while(adjEdgeExplorer.More()){
                         if(edge.IsSame(TopoDS::Edge(adjEdgeExplorer.Current()))){
                              value.adjacentFaces[compareIndex] = compareNode; 
                         }
                         adjEdgeExplorer.Next();
                    }
               }
          }
     }
}

void AAGAnalyzer::printAAG() const
{
     for (const auto node : AAG)
     {
          const int index = node.first;
          const AAGNode& value = node.second;

          std::cout << "Face " << index << ": " << value.surfaceType << "\n";
          std::cout << " Adjacent Facese: ";
          for (const auto &adjFace : value.adjacentFaces)
          {
               std::cout << adjFace.first << " ";
          }
          std::cout << std::endl;
     }

     int planeCnt = 0;
     int cylinderCnt = 0;

     for(const auto node : AAG){
          const int index = node.first;
          const AAGNode& value = node.second;
          if(value.surfaceType == "PLANE"){
               planeCnt++;
               std::string fileName = "hole-plane" + std::to_string(planeCnt) + ".step";
               saveObjectToStep(value.face, fileName);
          }else if(value.surfaceType == "CYLINDER"){
               cylinderCnt++;
               std::string fileName = "hole-cylinder" + std::to_string(cylinderCnt) + ".step";
               saveObjectToStep(value.face, fileName);
          }
     }
     std::cout << "PLANE = " << planeCnt << ", CYLINDER = " << cylinderCnt << std::endl;
}