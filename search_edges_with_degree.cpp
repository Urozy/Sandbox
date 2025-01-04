#include "search_edges_with_degree.hpp"

#include <sc-memory/sc_memory_headers.hpp>

#include "keynodes/sc_set_keynodes.hpp"

ScAddr ScAgentFindEdgesWDegree::GetActionClass() const
{
  return ScSetKeynodes::action_find_edge_with_degree;
}

ScResult ScAgentFindEdgesWDegree::DoProgram(ScAction & action)
{

  auto const & graphAddr = action.GetArgument(ScKeynodes::rrel_1);
  int degrees[2];
  m_context.GetLinkContent(action.GetArgument(ScKeynodes::rrel_2), degrees[0]);
  m_context.GetLinkContent(action.GetArgument(ScKeynodes::rrel_3), degrees[1]);
  if (!m_context.IsElement(graphAddr))
  {
    SC_AGENT_LOG_ERROR("Action does not have argument.");
    return action.FinishWithError();
  }

  if (m_context.GetElementType(graphAddr) != ScType::ConstNodeStructure)
    {
        SC_THROW_EXCEPTION(utils::ExceptionInvalidParams, "Param of agent must be struct, not " << m_context.GetElementType(graphAddr));
        return action.FinishWithError();
    }

  ScIterator3Ptr const it3 = m_context.CreateIterator3( 
    graphAddr,
    ScType::ConstPermPosArc,
    ScType::ConstNode
  );
int countNodes=0;
ScIterator3Ptr const counter = m_context.CreateIterator3(
  graphAddr,
  ScType::ConstPermPosArc,
  ScType::ConstCommonEdge
);
while(counter->Next()) {
  countNodes++;
}
int degreeElement=0;
int degreeSecondElement=0;
std::string name1;
std::string name2;
  ScAddr const & resultStruct = m_context.GenerateStructure();
  while(it3->Next()) {
    ScAddr const & element = it3->Get(2);
    ScIterator3Ptr it3Inner = m_context.CreateIterator3
    (
    graphAddr,
    ScType::ConstPermPosArc,
    ScType::ConstNode
    );

    
    while(it3Inner->Next()) {
      ScAddr const & secondElement = it3Inner->Get(2);  
      if(secondElement != element){
        if(HaveAnEdge(element,secondElement, graphAddr)){
          degreeElement = CountDegree(element, graphAddr);
          degreeSecondElement = CountDegree(secondElement, graphAddr);
          name1 = m_context.GetElementSystemIdentifier(element);
          name2 = m_context.GetElementSystemIdentifier(secondElement);
          SC_LOG_INFO(name1);
          SC_LOG_INFO(degreeElement-2);
          SC_LOG_INFO(name2);
          SC_LOG_INFO(degreeSecondElement-2);
          if(degreeElement-2 == degrees[0] && degreeSecondElement-2 == degrees[1]) {
            m_context.GenerateConnector(ScType::ConstPermPosArc, resultStruct, element);
            m_context.GenerateConnector(ScType::ConstPermPosArc, resultStruct, secondElement);
            ScIterator3Ptr it3FindEdge = m_context.CreateIterator3(
              element,
              ScType::ConstCommonEdge,
              secondElement
            );
            if(it3FindEdge->Next()) {
              m_context.GenerateConnector(ScType::ConstPermPosArc, resultStruct, it3FindEdge->Get(1));
            }
          }
        }
      }
    }
  }
  
  
  action.SetResult(resultStruct);
  return action.FinishSuccessfully();
}

bool ScAgentFindEdgesWDegree::IsInStruct(ScAddr const &structure, ScAddr const &element)
{
    ScIterator3Ptr it3Checker = m_context.CreateIterator3
    (
        structure,
        ScType::ConstPermPosArc,
        element
    );

    return it3Checker->Next();
}

int ScAgentFindEdgesWDegree::CountDegree(ScAddr const & element, ScAddr const & graphAddr) {
  ScIterator3Ptr it3main = m_context.CreateIterator3
  (
    graphAddr,
    ScType::ConstPermPosArc,
    ScType::ConstNode
  );
  int degreeCounter = 0;
  while(it3main->Next()) {
    ScAddr const & secondElement = it3main->Get(2);
    if(HaveAnEdge(element,secondElement,graphAddr)){
      degreeCounter++;
    }
  }
  return degreeCounter;
}

bool ScAgentFindEdgesWDegree::HaveAnEdge(ScAddr const &element, ScAddr const &secondElement, ScAddr const & graphAddr) {
  ScIterator3Ptr it3CheckEdge = m_context.CreateIterator3(
    element,
    ScType::ConstCommonEdge,
    secondElement
  );
  if(it3CheckEdge->Next() && IsInStruct(graphAddr, it3CheckEdge->Get(1))){
    return true;
  }
  return false;
}