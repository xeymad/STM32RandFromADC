# STM32RandFromADC
Implementation of a Random Number Generator (RNG) in STM32F401RE Nucleo Board using ADC 
# Achieved Speed
This RNG returns a random number of 32 bits every 2 milliseconds by using Analog Digital Controller with DMA.  
In 1 second there are 500 computations, which means that assested speed of the RNG is 16 Kbps.
> [!NOTE]
> To assest a minimal quality of this RNG, a generated file from UART (data2.adc) is tested in the [NIST SP800-22rev1a test suite](https://csrc.nist.gov/projects/random-bit-generation/documentation-and-software).  
The output is displayed in file ```console_output.txt```.
