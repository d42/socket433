#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

typedef unsigned long remote_code;
short code_size = 24;

#define ON_1 0x11
#define ON_2 0x21
#define ON_3 0x31

#define OFF_1 0x10
#define OFF_2 0x20
#define OFF_3 0x30


remote_code code_on_1 = 349491;
remote_code code_on_2 = 349635;
remote_code code_on_3 = 349955;

remote_code code_off_1 = 349500;
remote_code code_off_2 = 349644;
remote_code code_off_3 = 349964;


remote_code can_haz_code(char keycode) {
        remote_code code;
        switch(keycode) {
            case ON_1:
                code = code_on_1;
                break;
            case ON_2:
                code = code_on_2;
                break;
            case ON_3:
                code = code_on_3;
                break;

            case OFF_1:
                code = code_off_1;
                break;
            case OFF_2:
                code = code_off_2;
                break;
            case OFF_3:
                code = code_off_3;
                break;
            }
        return code;
    
    }

void setup() {
    Serial.begin(9600);
    mySwitch.enableTransmit(10);
    mySwitch.setProtocol(1, 200);
}

void loop() {
    if(Serial.available() > 0) {
        char keycode = Serial.read();
        remote_code code = can_haz_code(keycode);
        mySwitch.send(code, code_size);
    }
}
