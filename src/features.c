#include <estia-image.h>
#include <stdio.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld() {
    printf("Hello World !");
}

void dimension(char* source_path) {
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d\n", width, height);
}


void first_pixel (char *source_path){
    int R, G, B;
    
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R=data[0];
    G=data[1];
    B=data[2];
    printf("first_pixel: %d, %d, %d \n", R, G, B);
}

void tenth_pixel (char *source_path) {
    int R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R=data[27];
    G=data[28];
    B=data[29];
    printf("tenth_pixel: %d, %d, %d \n", R, G, B);
}

void second_line(char *source_path) {
    int R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R=data[3*width];
    G=data[3*width+1];
    B=data[3*width+2];
    printf("second_line: %d, %d, %d \n", R, G, B);
}

void print_pixel( char *filename, int x, int y ) {
    int R, G, B, i;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(filename, &data, &width, &height, &channel_count);
    if (x>width || y>height) {
        printf("1NULL %d %d\n", width, height);
    }
    else if (data==NULL) {
        printf("2NULL\n");
    } else {
        i=channel_count*(width*y+x);
        R=data[i];
        G=data[i+1];
        B=data[i+2];
        printf("print_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
    }
}

void max_pixel(char *source_path) {
    int sum=0, i, j, x=0, y=0, current_sum=0,R,G,B,k;
    pixelRGB* pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0; j<height; j++) {
        for (i=0; i<width; i++) {
            pixel=get_pixel(data, width, height, channel_count, i, j );
            current_sum=pixel->R+pixel->G+pixel->B;
            if (sum<current_sum) {
                sum=current_sum;
                x=i;
                y=j;
            }
        }
    }
    k=channel_count*(width*y+x);
    R=data[k];
    G=data[k+1];
    B=data[k+2];
    printf("max_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
}

void min_pixel(char *source_path) {
    int sum=765, i, j, x=0, y=0, current_sum=0,R,G,B,k;
    pixelRGB* pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j=0; j<height; j++) {
        for (i=0; i<width; i++) {
            pixel=get_pixel(data, width, height, channel_count, i, j );
            current_sum=pixel->R+pixel->G+pixel->B;
            if (sum>current_sum) {
                sum=current_sum;
                x=i;
                y=j;
            }
        }
    }
    k=channel_count*(width*y+x);
    R=data[k];
    G=data[k+1];
    B=data[k+2];
    printf("min_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
}