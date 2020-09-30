//

#include <iostream>


namespace pini  {
    int cout = 12;
    char lettera = 'x';
}

using namespace pini;
//using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    char lettera = 'z';
    
    std::cout << "Hello, World! " << cout <<"\n";
    pini::lettera = lettera;
    std::cout << "lettera = " << lettera << "  lettera = " << pini::lettera  <<"\n\n\n\n";
    
    
    
    
    
    
    
    
    
    
    //-------------- Calcolo di numeri primi -----------------------//
    // ma il crivello di Eratostene è migliore!!
    
    int i, j, n;
    n= 100000;
    bool primo;
    primo = true;
    for (i=2; i<n; i++) {                 // posso fare di meglio, come minimo andare di due in due
        for (j = 2; j<(i/2+1); j++) {     // posso fare di meglio, uscire alla prima false e usare una while
            if (i%j == 0 ) primo = false; //    %  da il resto della divisione intera:  14%3 = 2
        }
        if (primo) std::cout  << "primo = " << i << std::endl;
        primo = true;
    }
        
    return 0;
}
