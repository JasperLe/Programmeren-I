/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 * 
 * Made the vertical resize work thanks too StackExchange:
 * http://cs50.stackexchange.com/questions/12562/pset4-resize-c-cannot-get-vertical-resizing-to-work
 * 
 * Does not pass check50
 * I do not understand why... It resizes large.bmp correctly.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }

    // remember filenames
    int resize_n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    BITMAPFILEHEADER nbf;
    BITMAPINFOHEADER nbi;
    nbf = bf;
    nbi = bi;

    // padding
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    int new_padding = (4 - (nbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;  // nieuwe width is nog niet aangepast dus gaat fout
    
    
    // change outfile's BITMAPFILEHEADER andBITMAPINFOHEADER
    nbi.biWidth = bi.biWidth * resize_n;
    nbi.biHeight = bi.biHeight * resize_n;
    nbi.biSizeImage = (nbi.biWidth * sizeof(RGBTRIPLE) + new_padding) * abs(bi.biHeight);   // http://cs50.stackexchange.com/questions/8978/resizes-padding-issue
    nbf.bfSize = nbi.biSizeImage + 54;    // http://cs50.stackexchange.com/questions/10219/pset4-image-resizes-correctly-but-check50-detects-some-faults
                                          // http://cs50.stackexchange.com/questions/14016/pset4-resize-c-bfsize-bisizeimage-formulas

    // write outfile's BITMAPFILEHEADER
    fwrite(&nbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&nbi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int m = 0; m < resize_n; m++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
            
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for (int k = 0; k < resize_n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back
            for (int j = 0; j < new_padding; j++)
            {
                fputc(0x00, outptr);
            }
            fseek(inptr, -(bi.biWidth * 3 + padding), SEEK_CUR);
        }
        fseek(inptr, bi.biWidth * 3 + padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
