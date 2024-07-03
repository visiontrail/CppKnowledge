/*
 * Windows平台下的默认宏定义
*/
#if defined( _MSC_VER )
	#if !defined( _CRT_SECURE_NO_WARNINGS )
		#define _CRT_SECURE_NO_WARNINGS		// This test file is not intended to be secure.
	#endif
#endif

int main( int argc, const char ** argv )
{

}
