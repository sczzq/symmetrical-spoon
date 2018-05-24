/**
 * 100$ send 10 red bag, which must larger than or equels 6$, and less than or equals 12$.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int maximum_index(float *r, int length);
int minimum_index(float *r, int length);
float m_random(float, float);
float sum(float *r, int length);
void rege(float *r, int length, float min, float max);
int check(float *r, int length, float min, float max);
void test();
float g_random(float min, float max);
void test2();
void test3();
void print_array(float *r, int length);
float w_random(float min, float max);

int remainSize = 10;
float remainMoney = 100.0;

int main(){
    int i=0;
//    test2();
    test3();
}

void test3(){
    int i=0;
    float s = 0;
    float r[11] = {0};
    srand(time(NULL));
    for(i=0; i<10; i++){
        r[i] = w_random(6.0, 12.0);
        s += r[i];
        printf("i: %d, %.2f,  ", i, r[i] );
        printf("sum %.2f\n", s);
    }
    print_array(r, 10);
}

void test2(){
    int i=0;
    float s = 0;
    float r[11] = {0};
    srand(time(NULL));
    for(i=0; i<11; i++){
        r[i] = m_random(6.0, 12.0);
        s += r[i];
        printf("i: %d, %.2f,  ", i, r[i] );
        printf("sum %.2f\n", s);
    }
    float ava = r[10] / 10;
    for(i=0; i<10; i++){
        if(ava + r[i] <= 12 && ava+r[i]>=6){
            r[i] += ava;
        }else if ( ava+ r[i] < 6 ){
            int t = maximum_index(r,10);
            r[t] += ava;
            printf("add %d=%.2f to r[%d]=%.2f\n", i, ava, t, r[t]);
        } else if( ava + r[i] > 12 ){
            int t = minimum_index(r, 10);
            r[t] += ava;
            printf("add %d=%.2f to r[%d]=%.2f\n", i, ava, t, r[t]);
        }
    }
    print_array(r, 10);
    printf("\n");
}

int maximum_index(float *r, int length){
     int i;
     float max = r[0];
     int max_index = 0;
     for(i=1; i<length; i++){
         if(max < r[i]){
             max_index = i;
             max = r[i];
         }
     }
     return max_index;
}

int minimum_index(float *r, int length){
     int i;
     float min = r[0];
     int min_index = 0;
     for(i=1; i<length; i++){
         if(min > r[i]){
             min_index = i;
             min = r[i];
         }
     }
     return min_index;
}

void print_array(float *r, int length){
     int i;
     float sum = 0;
     for(i=0; i<length; i++){
         printf("%.2f  ", r[i]);
         sum += r[i];
     }
     printf("\n");
     printf("sum: %.2f\n", sum);
}

int check(float *r, int length, float min, float max){
     int i=0, ret = 1;
     for(i=0; i<length; i++){
         if(r[i] > max || r[i] < min){
             ret = 0;
             break;
         }
     }
     return ret;
}

void rege(float *r, int length, float min, float max){
    int i=0;
    int j=0;
    float r_max = min, r_min = max;
    int r_max_index = 0, r_min_index = 0;
    for(j=0; j<length; j++){
        if(r[j] > r_max){
            r_max = r[j];
            r_max_index = j;
        }
        else if(r[j] < r_min){
            r_min = r[j];
            r_min_index = j;
        }
    }
    r[r_max_index] = r_max / 2;
    float ava = r_max / 18;
    for(i=0; i<length; i++){
        if(i == r_max_index)
            continue;
        r[i] += ava;
    }
    r[r_min_index] *= 2.0;
    ava = r_min / 18;
    ava = ava / 0.01;
    ava = ava * 100;
    for(i=0; i<length; i++){
         if(i==r_min_index)
             continue;
         r[i] -= ava;
    }
    return;
}

float sum(float *r, int length){
    int i=0;
    float s = 0;
    for(i=0; i<length; i++){
        s += r[i];
    }
    return s;
}

// assume this is WCHAT HAOBAO.
float w_random(float min, float max){
    float f;
    if(remainSize == 1)
        return remainMoney;
    f = g_random(min, remainMoney/remainSize*2);
    f = f > max ? max : f;
    f = f < min ? min : f;
    remainMoney -= f;
    remainSize--;
    printf("remainMoney: %.2f, remainSize: %d\n", remainMoney, remainSize);
    return f;
}

float m_random(float min, float max){
    float f;
    if(remainSize == 1)
        return remainMoney;
    f = g_random(min, max);
    f = f > max ? max : f;
    f = f < min ? min : f;
    remainMoney -= f;
    remainSize--;
    return f;
}

float g_random(float min, float max){
    float f;
    f = (random() / 1000) % 1000;
    f = min + (max - min)*f/1000.0;
    return f;
}

void test(){
     float sum = 0;
     float t_sum = 0;
     int i = 0, j=0;
     for(i=0; i<10; i++){
         j++;
         if(i==9){
              printf("%d: %.2f\n", j, 100.0 - sum);
              break;
         }
         float f = g_random(6.0, 12.0);
         sum += f;
         t_sum = 100.0 - sum;
         if(t_sum < 0 || (9-i)*6>t_sum || (9-i)*12<t_sum){
              i--;
         } else {
             printf("J: %d, i: %d, : %.2f, sum: %.2f, t_sum:%.2f\n", j, i, f, sum, t_sum);
         }
     }
     printf("\n");
}
