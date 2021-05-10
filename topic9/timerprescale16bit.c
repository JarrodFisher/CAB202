// Replace 0 with the correct value for each unknown cell.
double prescale_001 = 1; //1
double prescale_010 = 8; //2
double prescale_011 = 64; //3
double prescale_100 = 256; //4
double prescale_101 = 1024; //5
// counter freq. = 16MHz/prescaler
double count_frequency_001 = 16e6; //1
double count_frequency_010 = 2e6; //2
double count_frequency_011 = 25e4; //3
double count_frequency_100 = 625e2; //4
double count_frequency_101 = 15625; //5
// ovf. per. = 65536/counter freq.
double overflow_period_001 = 4.096e-3; //1
double overflow_period_010 = 0.032768; //2
double overflow_period_011 = 0.262144; //3
double overflow_period_100 = 1.048576; //4
double overflow_period_101 = 4.194304; //5
// ovf. freq. = 1/ovf. per.
double overflow_freq_001 = 244.140625; //1
double overflow_freq_010 = 30.51757813; //2
double overflow_freq_011 = 3.814697266; //3
double overflow_freq_100 = 0.9536743164; //4
double overflow_freq_101 = 0.2384185791; //5


// There is no test driver for this program.

int main() {
	for ( ;; ) {
	}

	return 0;
}