#include <stdio.h>
#include "morse.h"


void alphabet(char ch, char *pCode)
{
    switch ( ch )
    {
        case 'a': case 'A':
            sprintf(pCode, ".-");
            break;
        case 'b': case 'B':
            sprintf(pCode, "-...");
            break;
        case 'c': case 'C':
            sprintf(pCode, "-.-.");
            break;
        case 'd': case 'D':
            sprintf(pCode, "-..");
            break;
        case 'e': case 'E':
            sprintf(pCode, ".");
            break;
        case 'f': case 'F':
            sprintf(pCode, "..-.");
            break;
        case 'g': case 'G':
            sprintf(pCode, "--.");
            break;
        case 'h': case 'H':
            sprintf(pCode, "....");
            break;
        case 'i': case 'I':
            sprintf(pCode, "..");
            break;
        case 'j': case 'J':
            sprintf(pCode, ".---");
            break;
        case 'k': case 'K':
            sprintf(pCode, "-.-");
            break;
        case 'l': case 'L':
            sprintf(pCode, ".-..");
            break;
        case 'm': case 'M':
            sprintf(pCode, "--");
            break;
        case 'n': case 'N':
            sprintf(pCode, "-.");
            break;
        case 'o': case 'O':
            sprintf(pCode, "---");
            break;
        case 'p': case 'P':
            sprintf(pCode, ".--.");
            break;
        case 'q': case 'Q':
            sprintf(pCode, "--.-");
            break;
        case 'r': case 'R':
            sprintf(pCode, ".-.");
            break;
        case 's': case 'S':
            sprintf(pCode, "...");
            break;
        case 't': case 'T':
            sprintf(pCode, "-");
            break;
        case 'u': case 'U':
            sprintf(pCode, "..-");
            break;
        case 'v': case 'V':
            sprintf(pCode, "...-");
            break;
        case 'w': case 'W':
            sprintf(pCode, ".--");
            break;
        case 'x': case 'X':
            sprintf(pCode, "-..-");
            break;
        case 'y': case 'Y':
            sprintf(pCode, "-.--");
            break;
        case 'z': case 'Z':
            sprintf(pCode, "--..");
            break;
        default:
            pCode[0] = 0x00;
    }
}

void number(char ch, char *pCode)
{
    switch ( ch )
    {
        case '0':
            sprintf(pCode, "-----");
            break;
        case '1':
            sprintf(pCode, ".----");
            break;
        case '2':
            sprintf(pCode, "..---");
            break;
        case '3':
            sprintf(pCode, "...--");
            break;
        case '4':
            sprintf(pCode, "....-");
            break;
        case '5':
            sprintf(pCode, ".....");
            break;
        case '6':
            sprintf(pCode, "-....");
            break;
        case '7':
            sprintf(pCode, "--...");
            break;
        case '8':
            sprintf(pCode, "---..");
            break;
        case '9':
            sprintf(pCode, "----.");
            break;
        default:
            pCode[0] = 0x00;
    }
}

void punctuation(char ch, char *pCode)
{
    switch ( ch )
    {
        case '.':
            sprintf(pCode, ".-.-.-");
            break;
        case ':':
            sprintf(pCode, "---...");
            break;
        case ',':
            sprintf(pCode, "--..--");
            break;
        case ';':
            sprintf(pCode, "-.-.-.");
            break;
        case '?':
            sprintf(pCode, "..--..");
            break;
        case '=':
            sprintf(pCode, "-...-");
            break;
        case '\'':
            sprintf(pCode, ".----.");
            break;
        case '/':
            sprintf(pCode, "-..-.");
            break;
        case '!':
            sprintf(pCode, "-.-.--");
            break;
        case '-':
            sprintf(pCode, "-....-");
            break;
        case '_':
            sprintf(pCode, "..--.-");
            break;
        case '"':
            sprintf(pCode, ".-..-.");
            break;
        case '(':
            sprintf(pCode, "-.--.");
            break;
        case ')':
            sprintf(pCode, "-.--.-");
            break;
        case '$':
            sprintf(pCode, "...-..-");
            break;
        case '&':
            sprintf(pCode, ".-...");
            break;
        case '@':
            sprintf(pCode, ".--.-.");
            break;
        case '+':
            sprintf(pCode, ".-.-.");
            break;
        default:
            pCode[0] = 0x00;
    }
}

char *morse_code(char ch)
{
    static char _buf[16];

    if (((ch >= 'a') && (ch <= 'z')) ||
        ((ch >= 'A') && (ch <= 'Z')))
    {
        alphabet(ch, _buf);
    }
    else if ((ch >= '0') && (ch <= '9'))
    {
        number(ch, _buf);
    }
    else if ((ch >= 0x21) && (ch <= 0x7E))
    {
        punctuation(ch, _buf);
    }
    else if ((ch == 0x20) || (ch == '\t'))
    {
        _buf[0] = '/';
        _buf[1] = 0x00;
    }
    else
    {
        _buf[0] = 0x00;
    }

    return _buf;
}

