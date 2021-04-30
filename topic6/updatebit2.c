#include <stdio.h>
#include <stdlib.h>

void query_bits_h (
    unsigned char out_bit,
    unsigned char *out_var,
    unsigned char input_mask,
    unsigned char input_var
) {
    unsigned char output_mask = (1 << out_bit);

    if ( (input_var & input_mask) == input_mask ) {
        (*out_var) |= output_mask;
    } else {
        (*out_var) &= ~output_mask;
    }
}

unsigned char in_var_01, output_var_01;
unsigned char in_var_02, output_var_02;
unsigned char in_var_03, output_var_03;
unsigned char in_var_04, output_var_04;
unsigned char in_var_05, output_var_05;
unsigned char in_var_06, output_var_06;
unsigned char in_var_07, output_var_07;
unsigned char in_var_08, output_var_08;
unsigned char in_var_09, output_var_09;
unsigned char in_var_10, output_var_10;

void query_bits () {
    query_bits_h( 1, &output_var_01, (1 << 0), in_var_01 );
    query_bits_h( 7, &output_var_02, (1 << 3),  in_var_02 );
    query_bits_h( 0, &output_var_03, (1 << 0) | (1 << 1), in_var_03 );
    query_bits_h( 2, &output_var_04, (1 << 1) | (1 << 4), in_var_04 );
    query_bits_h( 3, &output_var_05, (1 << 0) | (1 << 1) | (1 << 5), in_var_05 );
    query_bits_h( 2, &output_var_06, (1 << 3) | (1 << 5) | (1 << 7), in_var_06 );
    query_bits_h( 3, &output_var_07, (1 << 0) | (1 << 3) | (1 << 5) | (1 << 6), in_var_07 );
    query_bits_h( 3, &output_var_08, (1 << 1) | (1 << 5) | (1 << 6) | (1 << 7), in_var_08 );
    query_bits_h( 3, &output_var_09, (1 << 0) | (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7), in_var_09 );
    query_bits_h( 2, &output_var_10, (1 << 1) | (1 << 2) | (1 << 3) | (1 << 6) | (1 << 7), in_var_10 );

}


void print_bits( const char * label, unsigned char val){
    printf("%s bits = {", label);
    
    int deja = 0;

    for (int i = 0; i <= 7; i++) {
        if ( (val & (1 << i)) ) {
            printf("%s%d", (deja ? ", " : ""), i);
            deja = 1;
        }
    }

    printf("}\n");
}

int main(int argc, char * argv[]) {
    unsigned char init_val = 0;
    unsigned char out_init = 0;
    
    if (argc > 1) init_val = atoi(argv[1]) & 255;
    if (argc > 2) out_init = atoi(argv[2]) & 255;

    in_var_01 = init_val;
    output_var_01 = out_init;

    in_var_02 = init_val;
    output_var_02 = out_init;

    in_var_03 = init_val;
    output_var_03 = out_init;

    in_var_04 = init_val;
    output_var_04 = out_init;

    in_var_05 = init_val;
    output_var_05 = out_init;

    in_var_06 = init_val;
    output_var_06 = out_init;

    in_var_07 = init_val;
    output_var_07 = out_init;

    in_var_08 = init_val;
    output_var_08 = out_init;

    in_var_09 = init_val;
    output_var_09 = out_init;

    in_var_10 = init_val;
    output_var_10 = out_init;

    query_bits();

    print_bits("Input Value         ", init_val);
    print_bits("Initial output Value", out_init);

    printf("\nSearch for bit 0.\n");
    printf("Set or clear bit 1:\n");
    print_bits("output_var_01", output_var_01);

    printf("\nSearch for bit 3.\n");
    printf("Set or clear bit 7:\n");
    print_bits("output_var_02", output_var_02);

    printf("\nSearch for bits 0, 1.\n");
    printf("Set or clear bit 0:\n");
    print_bits("output_var_03", output_var_03);

    printf("\nSearch for bits 1, 4.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_var_04", output_var_04);

    printf("\nSearch for bits 0, 1, 5.\n");
    printf("Set or clear bit 3:\n");
    print_bits("output_var_05", output_var_05);

    printf("\nSearch for bits 3, 5, 7.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_var_06", output_var_06);

    printf("\nSearch for bits 0, 3, 5, 6.\n");
    printf("Set or clear bit 3:\n");
    print_bits("output_var_07", output_var_07);

    printf("\nSearch for bits 1, 5, 6, 7.\n");
    printf("Set or clear bit 3:\n");
    print_bits("output_var_08", output_var_08);

    printf("\nSearch for bits 0, 2, 3, 5, 7.\n");
    printf("Set or clear bit 3:\n");
    print_bits("output_var_09", output_var_09);

    printf("\nSearch for bits 1, 2, 3, 6, 7.\n");
    printf("Set or clear bit 2:\n");
    print_bits("output_var_10", output_var_10);

    return 0;
}
