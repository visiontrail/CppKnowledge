#include "shared_Ptr_StrBlob.h"

int main(int argc, char **argv)
{
    StrBlob d1;
    {
        StrBlob d2 = {"1", "2", "3"};
        d1 = d2;
        d2.push_back("4");
    }

    for (int i = 0; i < 4; ++i)
	{
		std::cout << "content is " <<  std::endl;
	}
    
    return 0;
}

