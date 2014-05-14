#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

class jolly
{
public:
  jolly(std::istream & strm)
    : m_nbr()
    , m_strm(strm)
  {}
  
  void solve()
  {
    bool result = true;
    while(m_strm >> m_nbr)
    {
      result = true;
      m_data.resize(m_nbr);
      m_results.resize(m_nbr-1, false);
      std::fill(m_results.begin(), m_results.end(), false);
      
      for(int i=0; i < m_nbr; ++i)
      {
        m_strm >> m_data[i];
      }

      for(int i=0; i < m_nbr-1; ++i)
      {
        try
        {
          unsigned diff = abs(m_data[i] - m_data[i+1]);
          m_results.at(diff-1)=true;
        }
        catch(std::exception&)
        {
          result=false;
          break;
        }
      }

      if(result)
      {
        std::vector<bool>::iterator it = std::find(m_results.begin(), m_results.end(), false);
        result = (it != m_results.end())? false : true;
      }
      std::cout << (result? "Jolly" : "Not jolly") << std::endl;
    }
  }
  
  int                   m_nbr;
  std::vector<int>      m_data;
  std::vector<bool>     m_results;
  std::istream &        m_strm;
};

  int main() 
  {
//#define _my_test
#ifdef _my_test
    std::string input_str("4 1 4 2 3\n5 1 4 2 -1 6\n4 1 4 2 2\n1 1");
    std::istringstream input(input_str);
#else
#endif

#ifdef _my_test
    jolly j(input);
#else
    jolly j(std::cin);
#endif
    j.solve();
    return 0;
  }