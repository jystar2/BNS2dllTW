#include "pch.h"

#include <string>
#include <vector>

std::string Replace(std::string str, const std::string& from, const std::string& to);
int InStr(int StartIndex, std::string InpuStr, std::string FindStr);
std::string Left(std::string InpuStr, int Length);
std::string Right(std::string InpuStr, int Length);
int Len(std::string InpuStr);
std::vector<std::string> split(std::string s, std::string delimiter);
bool CompareName(std::string TmpName, std::string DestName);


std::string Replace(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


int InStr(int StartIndex, std::string InpuStr, std::string FindStr) {

    if (StartIndex > InpuStr.length() || InpuStr.length() == 0)
    {
        return 0;
    }
    else if (StartIndex > 0)
    {
        if (InpuStr.find(FindStr) != std::string::npos) {

            return InpuStr.find(FindStr, (long)StartIndex - 1) + 1; // 开始搜索的索引位置，第一个字符是 0 ，第二个是 1  ,如果此字符串中没有这样的字符，则返回 -1。
        }
        else {
            return 0;
        }
    }
    return 0;
}

std::string Left(std::string InpuStr, int Length)
{
    if (Length < InpuStr.length())
    {
        return InpuStr.substr(0, Length);
    }
    else
    {
        return InpuStr;
    }
}

std::string Right(std::string InpuStr, int Length)
{
    if (Length < InpuStr.length())
    {
        return InpuStr.substr(InpuStr.length() - Length);
    }
    else
    {
        return InpuStr;
    }
}

int Len(std::string InpuStr)
{
    return InpuStr.length();
}


std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool CompareName(std::string TmpName, std::string DestName)
{

    std::vector<std::string> TmpArr;
    bool TmpResult;
    std::string TmpSearch;
    int SearchResult = 0;
    int SearchResult2 = 0;


    TmpResult = false;
    try {

        if (InStr(1, TmpName, "#") > 0)
        {
            if (Right(TmpName, 1) == "#" && Left(TmpName, 1) == "#")
            {
                TmpSearch = Replace(TmpName, "#", "");
                SearchResult = InStr(1, DestName, TmpSearch);
                if (SearchResult > 0 && SearchResult + Len(TmpSearch) <= Len(DestName))
                {
                    TmpResult = true;
                }
            }
            else if (Left(TmpName, 1) == "#")
            {
                TmpSearch = Right(TmpName, Len(TmpName) - 1);
                SearchResult = InStr(1, DestName, TmpSearch);
                if (Right(DestName, Len(TmpSearch)) == TmpSearch && Len(DestName) >= Len(TmpSearch))
                {
                    TmpResult = true;
                }
            }
            else if (Right(TmpName, 1) == "#")
            {
                TmpSearch = Left(TmpName, Len(TmpName) - 1);
                if (Left(DestName, Len(TmpSearch)) == TmpSearch && Len(DestName) >= Len(TmpSearch))
                {
                    TmpResult = true;
                }
            }
            else
            {
                TmpArr = split(TmpName, "#");
                if (TmpArr.size() > 0)
                {
                    SearchResult = InStr(1, DestName, TmpArr[0]);
                    SearchResult2 = InStr(1, DestName, TmpArr[1]);
                }

                if (Left(DestName, Len(TmpArr[0])) == TmpArr[0] && Right(DestName, Len(TmpArr[1])) == TmpArr[1])
                {
                    TmpResult = true;
                }

            }
        }
        else
        {
            if (TmpName == DestName)
            {
                TmpResult = true;
            }
        }
    }
    catch (char* e) {

    }

    return TmpResult;
}


int CLNG(std::string TmpVal)
{
    return atoi(TmpVal.c_str());
}