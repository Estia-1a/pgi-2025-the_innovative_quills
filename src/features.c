#include <estia-image.h>
#include <stdio.h>
#include <stdlib.h>

#include "features.h"
#include "utils.h"

/**
 * @brief Here, you have to code features of the project.
 * Do not forget to commit regurlarly your changes.
 * Your commit messages must contain "#n" with: n = number of the corresponding feature issue.
 * When the feature is totally implemented, your commit message must contain "close #n".
 */

void helloWorld()
{
    printf("Hello World !");
}

void dimension(char *source_path)
{
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    printf("dimension: %d, %d\n", width, height);
}

void first_pixel(char *source_path)
{
    int R, G, B;

    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R = data[0];
    G = data[1];
    B = data[2];
    printf("first_pixel: %d, %d, %d \n", R, G, B);
}

void tenth_pixel(char *source_path)
{
    int R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R = data[27];
    G = data[28];
    B = data[29];
    printf("tenth_pixel: %d, %d, %d \n", R, G, B);
}

void second_line(char *source_path)
{
    int R, G, B;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    R = data[3 * width];
    G = data[3 * width + 1];
    B = data[3 * width + 2];
    printf("second_line: %d, %d, %d \n", R, G, B);
}

void print_pixel(char *filename, int x, int y)
{
    int R, G, B, i;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(filename, &data, &width, &height, &channel_count);
    if (x > width || y > height)
    {
        printf("1NULL %d %d\n", width, height);
    }
    else if (data == NULL)
    {
        printf("2NULL\n");
    }
    else
    {
        i = channel_count * (width * y + x);
        R = data[i];
        G = data[i + 1];
        B = data[i + 2];
        printf("print_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
    }
}

void max_pixel(char *source_path)
{
    int sum = 0, i, j, x = 0, y = 0, current_sum = 0, R, G, B, k;
    pixelRGB *pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            pixel = get_pixel(data, width, height, channel_count, i, j);
            current_sum = pixel->R + pixel->G + pixel->B;
            if (sum < current_sum)
            {
                sum = current_sum;
                x = i;
                y = j;
            }
        }
    }
    k = channel_count * (width * y + x);
    R = data[k];
    G = data[k + 1];
    B = data[k + 2];
    printf("max_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
}

void min_pixel(char *source_path)
{
    int sum = 765, i, j, x = 0, y = 0, current_sum = 0, R, G, B, k;
    pixelRGB *pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            pixel = get_pixel(data, width, height, channel_count, i, j);
            current_sum = pixel->R + pixel->G + pixel->B;
            if (sum > current_sum)
            {
                sum = current_sum;
                x = i;
                y = j;
            }
        }
    }
    k = channel_count * (width * y + x);
    R = data[k];
    G = data[k + 1];
    B = data[k + 2];
    printf("min_pixel (%d, %d): %d, %d, %d \n", x, y, R, G, B);
}

void max_component(char *source_path, char *L)
{
    int i, j, x = 0, y = 0, Max = 0;
    pixelRGB *pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    switch (L[0])
    {
    case 'R':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Max < pixel->R)
                {
                    Max = pixel->R;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    case 'G':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Max < pixel->G)
                {
                    Max = pixel->G;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    case 'B':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Max < pixel->B)
                {
                    Max = pixel->B;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    default:
        printf("Erreur entrez une valeur R, G ou B");
        break;
    }
    printf("max_component %s (%d, %d): %d \n", L, x, y, Max);
}

void min_component(char *source_path, char *L)
{
    int i, j, x = 0, y = 0, Min = 765;
    pixelRGB *pixel;
    int width, height, channel_count;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    switch (L[0])
    {
    case 'R':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Min > pixel->R)
                {
                    Min = pixel->R;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    case 'G':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Min > pixel->G)
                {
                    Min = pixel->G;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    case 'B':
        for (j = 0; j < height; j++)
        {
            for (i = 0; i < width; i++)
            {
                pixel = get_pixel(data, width, height, channel_count, i, j);
                if (Min > pixel->B)
                {
                    Min = pixel->B;
                    x = i;
                    y = j;
                }
            }
        }
        break;
    default:
        printf("Erreur entrez une valeur R, G ou B");
        break;
    }
    printf("min_component %s (%d, %d): %d \n", L, x, y, Min);
}

void stat_report(char *source_path)
{
    FILE *fichier = fopen("fichier.txt", "w");
    freopen("fichier.txt", "w", stdout);
    max_pixel(source_path);
    min_pixel(source_path);
    max_component(source_path, "R");
    max_component(source_path, "G");
    max_component(source_path, "B");
    min_component(source_path, "R");
    min_component(source_path, "G");
    min_component(source_path, "B");
    fclose(fichier);
}

void color_red(char *source_path)
{
    int width, height, channel_count, i, j, k = 0;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            data[k + 1] = 0;
            data[k + 2] = 0;
            k += channel_count;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_green(char *source_path)
{
    int width, height, channel_count, i, j, k = 0;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            data[k] = 0;
            data[k + 2] = 0;
            k += channel_count;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}
void color_blue(char *source_path)
{
    int width, height, channel_count, i, j, k = 0;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            data[k] = 0;
            data[k + 1] = 0;
            k += channel_count;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray(char *source_path)
{
    int width, height, channel_count, i, j;
    unsigned char *data;
    pixelRGB *pixel;
    unsigned char value;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            pixel = get_pixel(data, width, height, channel_count, i, j);
            value = (pixel->R + pixel->G + pixel->B) / 3;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_invert(char *source_path)
{
    int width, height, channel_count, i, j, k = 0;
    unsigned char *data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            data[k] = 255 - data[k];
            data[k + 1] = 255 - data[k + 1];
            data[k + 2] = 255 - data[k + 2];
            k += channel_count;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void color_gray_luminance(char *source_path)
{
    int width, height, channel_count, i, j;
    unsigned char *data;
    pixelRGB *pixel;
    unsigned char value;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            pixel = get_pixel(data, width, height, channel_count, i, j);
            value = pixel->R * 0.21 + pixel->G * 0.72 + pixel->B * 0.07;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void color_desaturate(char *source_path)
{
    int width, height, channel_count, i, j;
    unsigned char *data;
    pixelRGB *pixel;
    unsigned char value;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            pixel = get_pixel(data, width, height, channel_count, i, j);
            value = (min(min(pixel->R, pixel->G), pixel->B) + (max(max(pixel->R, pixel->G), pixel->B))) / 2;
            pixel->R = value;
            pixel->G = value;
            pixel->B = value;
        }
    }
    write_image_data("image_out.bmp", data, width, height);
}

void rotate_cw(char *source_path)
{
    int width, height, channel_count, i, j, k, x_new, y_new;
    unsigned char *data, *new_data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    new_data = malloc(width * height * channel_count * sizeof(unsigned char));
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            for (k = 0; k < channel_count; k++)
            {
                x_new = -j + height - 1;
                y_new = i;
                new_data[(y_new * height + x_new) * channel_count + k] = data[(j * width + i) * channel_count + k];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, height, width);
    free(new_data);
}

void rotate_acw(char *source_path)
{
    int width, height, channel_count, i, j, k, x_new, y_new;
    unsigned char *data, *new_data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    new_data = malloc(width * height * channel_count * sizeof(unsigned char));
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            for (k = 0; k < channel_count; k++)
            {
                x_new = j;
                y_new = -i + width - 1;
                new_data[(y_new * height + x_new) * channel_count + k] = data[(j * width + i) * channel_count + k];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, height, width);
    free(new_data);
}

void mirror_horizontal(char *source_path)
{
    int width, height, channel_count, i, j, k, x_new;
    unsigned char *data, *new_data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    new_data = malloc(width * height * channel_count * sizeof(unsigned char));
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            for (k = 0; k < channel_count; k++)
            {
                x_new = width - 1 - i;
                new_data[(j * height + x_new) * channel_count + k] = data[(j * width + i) * channel_count + k];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
}

void mirror_vertical(char *source_path)
{
    int width, height, channel_count, i, j, k, y_new;
    unsigned char *data, *new_data;
    read_image_data(source_path, &data, &width, &height, &channel_count);
    new_data = malloc(width * height * channel_count * sizeof(unsigned char));
    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            for (k = 0; k < channel_count; k++)
            {
                y_new = height - 1 - j;
                new_data[(y_new * height + i) * channel_count + k] = data[(j * width + i) * channel_count + k];
            }
        }
    }
    write_image_data("image_out.bmp", new_data, width, height);
    free(new_data);
}

void mirror_total(char *source_path)
{
    mirror_horizontal(source_path);
    mirror_vertical("image_out.bmp");
}
