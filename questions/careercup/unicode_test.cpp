#define IS_IN_RANGE(c, f, l)    (((c) >= (f)) && ((c) <= (l)))

int UTF8BufferToUTF32Buffer(char *Data, int DataLen, unsigned long *Buffer, int BufLen, int *Eaten)
{
    if( Eaten )
    {
        *Eaten = 0;
    }

    int Result = 0;

    unsigned char b, b2;
    unsigned char *ptr = (unsigned char*) Data;
    unsigned long uc;

    int i = 0;
    int seqlen;

    while( i < DataLen )
    {
        if( (Buffer) && (!BufLen) )
            break;

        b = ptr[i];

        if( (b & 0x80) == 0 )
        {
            uc = (unsigned long)(b & 0x7F);
            seqlen = 1;
        }
        else if( (b & 0xE0) == 0xC0 )
        {
            uc = (unsigned long)(b & 0x1F);
            seqlen = 2;
        }
        else if( (b & 0xF0) == 0xE0 )
        {
            uc = (unsigned long)(b & 0x0F);
            seqlen = 3;
        }
        else if( (b & 0xF8) == 0xF0 )
        {
            uc = (unsigned long)(b & 0x07);
            seqlen = 4;
        }
        else
        {
            uc = 0;
            return -1;
        }

        if( (i+seqlen) > DataLen )
        {
            return -1;
        }

        for(int j = 1; j < seqlen; ++j)
        {
            b = ptr[i+j];

            if( (b & 0xC0) != 0x80 )
            {
                return -1;
            }
        }

        switch( seqlen )
        {
            case 2:
            {
                b = ptr[i];

                if( !IS_IN_RANGE(b, 0xC2, 0xDF) )
                {
                    return -1;
                }

                break;
            }

            case 3:
            {
                b = ptr[i];
                b2 = ptr[i+1];

                if( ((b == 0xE0) && !IS_IN_RANGE(b2, 0xA0, 0xBF)) ||
                    ((b == 0xED) && !IS_IN_RANGE(b2, 0x80, 0x9F)) ||
                    (!IS_IN_RANGE(b, 0xE1, 0xEC) && !IS_IN_RANGE(b, 0xEE, 0xEF)) )
                {
                    return -1;
                }

                break;
            }

            case 4:
            {
                b = ptr[i];
                b2 = ptr[i+1];

                if( ((b == 0xF0) && !IS_IN_RANGE(b2, 0x90, 0xBF)) ||
                    ((b == 0xF4) && !IS_IN_RANGE(b2, 0x80, 0x8F)) ||
                    !IS_IN_RANGE(b, 0xF1, 0xF3) )
                {
                    return -1;
                }

                break;
            }
        }

        for(int j = 1; j < seqlen; ++j)
        {
            uc = ((uc << 6) | (unsigned long)(ptr[i+j] & 0x3F));
        }

        if( Buffer )
        {
            *Buffer++ = uc;
            --BufLen;
        }

        ++Result;
        i += seqlen;
    }

    if( Eaten )
    {
        *Eaten = i;
    }

    return Result;
}

{
    std::string filename = "...";

    unsigned long ch;
    int eaten;

    std::string::size_type i = 0;
    while( i < filename.length() )
    {
        if( UTF8BufferToUTF32Buffer(&filename[i], filename.length()-i, &ch, 1, &eaten) == 1 )
        {
            i += eaten;
        }
        else
        {
            // replace the character at filename[i] with your chosen
            // escaping, and then increment i by the number of
            // characters used...
        }
    }
}
