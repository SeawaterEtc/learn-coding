#include <stdio.h>

int convolution (int m1[3][3], int kernel[3][3]){
    int convolved =0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            convolved = convolved + (m1[3][3] * kernel[3][3]);
        }

    }
    return convolved;
}


int main () {
    int m1[3][3] = {{1,0,1},
                    {1,1,1},
                    {0,0,0}};
    int kernel[3][3] = {{1,0,1},
                        {1,1,1},
                        {0,0,0}};

    int convolved = convolution (m1, kernel);
    printf ("convolved = %d", convolved); 
    return 0;
}

