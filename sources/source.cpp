#include "header.hpp"
#include <iostream>

int main() {
    stack<int> st;
  
    st.push_emplace(1, 2, 3, 4);
    std::cout << "header: " << st.head() << std::endl;
    
    st.push_emplace(5);
    std::cout << "header: " << st.head() << std::endl;
     
    st.pop();
    std::cout << "header: " << st.head() << std::endl;
}
