// otl_test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <sstream>
using namespace std;

#include <otlv4.h>

// User Defined Headers
#include "CommonUtil.h"
#include "DataBaseConfig.h"
//

// Global Variables
otl_connect	db;
//

// Methods
void db_initialize( otl_connect& db );
void set_db_configuration( std::ostringstream& ost);
//

void db_initialize( otl_connect& db )
{
	db.otl_initialize();
}

/*
	ost << "dtmuser/dtmuser@115.92.96.59/DASSTECH";
*/
void set_db_configuration( std::ostringstream& ost)
{		
		ost << str_db_user_id		<< "/"
			<< str_db_user_passwd	<< "@"
			<< str_db_ip_address	<< "/"
			<< str_db_service_name
			;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MEASURE_TIME_WITH_IDX_START(main_function)

	try
	{	
		db_initialize( db );

		std::ostringstream ost;
		set_db_configuration(ost);

		db.rlogon( ost.str().c_str() );

	
		
		otl_stream i(10, // buffer size 
              "select * from DTM_PROJECT",
              db // connect object
        ); 

		string a;
		otl_datetime dt;
		while( !i.eof() )
		{
			i >> a;cout << a << " : ";
			i >> dt;cout << dt<< " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			i >> a;cout << a << " : ";
			cout << a << endl;
		}
		
		db.logoff();
		db.otl_terminate();		
	}
	catch(otl_exception& p)
	{
		cerr << p.msg << endl;
		cerr << p.stm_text << endl;
		cerr << p.var_info << endl;
	}	
	MEASURE_TIME_WITH_IDX_END(main_function)
	return 0;
}

