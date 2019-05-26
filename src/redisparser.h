#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <vector>
#include <utility>

#include "redisvalue.h"

class RedisParser
{
public:
    RedisParser();

    enum ParseResult {
        Completed,
        Incompleted,
        Error,
    };

     std::pair<size_t, ParseResult> parse(const char *ptr, size_t size);

     RedisValue result();

protected:
     std::pair<size_t, ParseResult> parseChunk(const char *ptr, size_t size);

    inline bool isChar(int c)
    {
        return c >= 0 && c <= 127;
    }

    inline bool isControl(int c)
    {
        return (c >= 0 && c <= 31) || (c == 127);
    }

     long int bufToLong(const char *str, size_t size);

private:
    enum State {
        Start = 0,
        StartArray = 1,

        String = 2,
        StringLF = 3,

        ErrorString = 4,
        ErrorLF = 5,

        Integer = 6,
        IntegerLF = 7,

        BulkSize = 8,
        BulkSizeLF = 9,
        Bulk = 10,
        BulkCR = 11,
        BulkLF = 12,

        ArraySize = 13,
        ArraySizeLF = 14,
    };

    std::stack<State> states;

    long int bulkSize;
    std::vector<char> buf;
    RedisValue redisValue;

    // temporary variables
    std::stack<long int> arraySizes;
    std::stack<RedisValue> arrayValues;

    static const char stringReply = '+';
    static const char errorReply = '-';
    static const char integerReply = ':';
    static const char bulkReply = '$';
    static const char arrayReply = '*';
};


#endif // PARSER_H
