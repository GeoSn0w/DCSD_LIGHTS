// This project is built by GeoSn0w (@FCE365) on top of Mathieu Hautebas' DCSD STATUS project that can be found at
// https://github.com/matteyeux/dcsd_status

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <ftdi.h>
#include <unistd.h>

int christmasLightPattern();
int light_up (int led);
int led_to_light = 0;

int christmasLightPattern(){
    printf("[i] Doing Christmas Light Pattern\n");
    light_up(4);
    sleep(1);
    light_up(2);
    sleep(1);
    light_up(1);
    sleep(1);
    light_up(3);
    sleep(1);
    light_up(4);
    sleep(1);
    light_up(1);
    sleep(1);
    light_up(2);
    sleep(1);
    return 0;
}
int light_up (int led){
    struct ftdi_context *ftdi;
    int fopen;
    long int tab[5] = {0xF0, 0xF2, 0xF8, 0xF1, 0xFB};
    unsigned char buf[1];
    static int led_status = -1;
    
    if (led == led_status)
    {
        //Ignore instruction to light the same LED
        return 0;
    } else {
        led_status = led;
    }
    
    ftdi = ftdi_new();
    
    if (ftdi == 0){
        fprintf(stderr, "\n[!] The ftdi_new failed\n");
        return -1;
    }
    
    fopen = ftdi_usb_open(ftdi, 0x0403, 0x8a88);
    
    if (fopen < 0){
        fprintf(stderr, "\n[!] Cannot find the DCSD Cable connected. Please plug it in and try again!\n");
        exit(EXIT_FAILURE);
    }
    
    fopen = ftdi_set_bitmode(ftdi, tab[led], BITMODE_CBUS);
    
    if (fopen < 0){
        ftdi_get_error_string(ftdi);
        ftdi_usb_close(ftdi);
        ftdi_free(ftdi);
        exit(-1);
    }
    fopen = ftdi_read_pins(ftdi, &buf[0]);
    
    if (fopen < 0){
        ftdi_usb_close(ftdi);
        ftdi_free(ftdi);
        exit(-1);
    }
    ftdi_usb_close(ftdi);
    ftdi_free(ftdi);
    
    return 0;
}

int main()
{
    system("clear");
    printf("DCSD LIGHTS by GeoSn0w (@FCE365)\nSpecial thanks to @matteyeux for his DCSD_STATUS project.\n\n");
    light_up(4);
    christmasLightPattern();
    do {
        
        printf("Turn on: ");
        light_up(led_to_light);
        
    } while (scanf("%d", &led_to_light)); //Get user input
    
	return 0;
}
