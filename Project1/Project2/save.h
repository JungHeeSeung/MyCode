#pragma once

#include<string>
#include<fstream>
#include<algorithm>
#include<iterator>
#include<chrono>

void save(std::string fname)
{
	// fname을 읽기 모드로 연다.
	std::ifstream in(fname);


	// 하드디스크에 저장 할 파일을 덧붙여쓰기 모드로 연다.
	std::ofstream out("2019_03_19 STL 화56금23 강의 저장.txt", std::ios::app);

	// 저장한 시간도 기록한다.
	// 1970 이후의 틱수를 얻어온다.
	auto tick = std::chrono::system_clock::now();
	// time 형식으로 변환한다.
	auto time = std::chrono::system_clock::to_time_t(tick);
	//글자로 바꾼다.
	std::string date(ctime(&time));

	//ctime_s( &time );
	out << std::endl << std::endl;
	out << "==========================" << std::endl;
	out << " " << date;
	out << "==========================" << std::endl;
	out << std::endl;


	// 읽은 모든 내용을 쓴다.
		//copy(어디부터, 어디까지, 어디로);
	copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out)
	);
	// buf 를 붙여서 빈칸도 입력한다.

}