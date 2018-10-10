/* Maria Maldonado 1000061100 */

#include "MyLib.h"

void ConvertDecimalToBinary(int decimal_number)
{
    int i;
    int BinaryArray[8];
    for (i=7 ; i>=0; i--){
        if (1 & decimal_number)
        {
            BinaryArray[i] = 1;
        }

        else
        {
            BinaryArray[i] = 0;
        }
        decimal_number = decimal_number >> 1;
    }

    int j=0;
    for (j=0; j<=7; j++)
          printf("%d", BinaryArray[j]);
}
