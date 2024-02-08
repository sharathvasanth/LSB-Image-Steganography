/*
DOCUMENTATION
NAME : SHARATH VASANTH
DATE : 28-10-2023
DESCRIPTION : Project_1: Steganography
SAMPLE INPUT: pass the magic string and beautiful.bmp images
SAMPLE OUTPUT:Decoding and encoding operation is done
DOCUMENTATION
 */
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

/* Passing arguments through command line arguments */
int main(int argc, char *argv[])
{
    // Function call for check operation type
    if (check_operation_type(argv) == e_encode)
    {
	printf("Selected encoding\n");

	// Declare structure variable
	EncodeInfo encInfo;
	// Read and validate encode arguments 
	if (read_and_validate_encode_args(argv, &encInfo) == e_success)
	{
	    printf("Read and validate encode arguments is a success\n");
	    printf("<------Started Encoding--------->\n");

	    // Function call for encoding
	    if (do_encoding(&encInfo) == e_success)
	    {
		printf("<--------Completed encoding-------->\n");
	    }
	    else
	    {
		printf("Failed to encode\n");
		//return -1;
		return e_failure;
	    }
	}
	else
	{
	    printf("Read and validate encode arguments is a failure\n");
	    //return -1;
	    return e_failure;
	}
    }
    // Function call for check operation type
    else if (check_operation_type(argv) == e_decode)
    {
	printf("Selected decoding\n");

	// Declare structure variables
	DecodeInfo decInfo;
	if (read_and_validate_decode_args(argv, &decInfo) == d_success)
	{
	    printf("Read and validate decode arguments is a success\n");
	    printf("<--------Started Decoding---------->\n");

	    // Function call for do decoding
	    if (do_decoding(&decInfo) == d_success)
	    {
		printf("<---------Completed decoding--------->\n");
	    }
	    else
	    {
		printf("Failed to decode\n");
		// return -1;
		return e_failure;
	    }
	}  
	else
	{
	    printf("Read and validate decode arguments is a failure\n");
	    //return -1;
	    return e_failure;
	}
    } 
    else
    {
	//Else print the error messeage invalid operation
	printf("Invalid option\nKindly pass for\nEncoding: ./a.out -e beautiful.bmp secret.txt stego.bmp\nDecoding: ./a.out -d stego.bmp decode.txt\n");
    }
    return 0;
}

