#pragma once

#include <string>
#include <vector>

std::string Replace(std::string str, const std::string& from, const std::string& to);
int InStr(int StartIndex, std::string InpuStr, std::string FindStr);
std::string Left(std::string InpuStr, int Length);
std::string Right(std::string InpuStr, int Length);
int Len(std::string InpuStr);
std::vector<std::string> split(std::string s, std::string delimiter);
bool CompareName(std::string TmpName, std::string DestName);
int CLNG(std::string TmpVal);