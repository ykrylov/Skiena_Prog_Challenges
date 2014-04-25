#include <iostream>
#include <sstream>
#include <map>

class solver_3n_1
{
public:
  solver_3n_1(std::istream & strm)
    : m_from()
    , m_to()
    , m_res(-1)
    , m_strm(strm)
  {
  }
  
  void solve()
  {
    while(m_strm >> m_from >> m_to)
    {
      long long from = m_from, to = m_to;
      if(m_from > m_to)
        std::swap(from, to);

      for(;from <= to; ++from)
      {
        std::map<long long, long long>::iterator it = m_cash.find(from);
        
        if(it != m_cash.end())
        {
          m_res = std::max(m_res, it->second);         
        }
        else
        {
          long long res = find_cycle(from);
          m_cash[from] = res;
          m_res = std::max(m_res, res);
        }

      }
      std::cout << m_from << ' ' << m_to << ' ' << m_res << std::endl;
      m_res=-1;
    }
  }

private:
  long long find_cycle(long long num)
  {
    if (num <= 0) return 0;
    long long res = 1;
    while(num != 1)
    {
      if(num & 1) num = num * 3 + 1;
      else        num /= 2;        
      ++res;
    }
    return res;
  }

  long long m_from;
  long long m_to;
  long long m_res;
  std::istream & m_strm;
  std::map<long long, long long>  m_cash;
};

int main() 
{
//#define _my_test
#ifdef _my_test
  std::string input_str("1 10\n 100 200\n999800 1000000");
  std::istringstream input(input_str);
#else
#endif

#ifdef _my_test
    solver_3n_1 l(input);
#else
    solver_3n_1 l(std::cin);
#endif
    l.solve();
  return 0;
}