#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc ,char *argv[])
{
    if(argc < 3)
    {
        printf("Lesser number of arguments\n");
    }
    else
    {
        //check if -e is passed
        if(check_operation_type(argv) == e_encode)
        {
            printf("Selected Encoding\n");
            EncodeInfo e;
            if(read_and_validate_encode_args(argv, &e) == e_success)
            {
                printf("reading and validating the arguments is a success\n");
                printf("-----------Started Encoding -------------\n");
                if(do_encoding(&e) == e_success)
                {
                    printf("Encoding is successful\n");
                }
                else
                {
                    printf("Failed to perform encoding");
                }
            }
            else
            {
                printf("Failed to read and validate the encoding arguments\n");
            }
        }
        else if(check_operation_type(argv) == e_decode )
        {
            printf("Selected Decoding\n");
            DecodeInfo d;
            if(read_and_validate_decode_args(argv, &d) == e_success)
            {
                printf("reading and validating the arguments is a success\n");
                printf("-----------Started Decoding -------------\n");
                if(do_decoding(&d) == e_success)
                {
                    printf("Decoding is successful\n");
                }
                else
                {
                    printf("Failed to perform Decoding");
                }
            }
            else
            {
                printf("Failed to read and validate the encoding arguments\n");
            }
        }
        else
        {
            printf("Invalid option. Please pass\nFor Encoding : ./a.out -e beautiful.bmp secret.txt [stego.bmp]\n For Decoding : ./a.out -d stego.bmp [decode.txt]\n");
        }
    }
    return 0;
}

OperationType check_operation_type(char *argv[])
{
    if(strcmp(argv[1],"-e") == 0)
    {
        return e_encode;
    }
    else if(strcmp(argv[1],"-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}
