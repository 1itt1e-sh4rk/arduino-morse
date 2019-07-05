const int _pin = 2;
const int _dottime = 250;

void dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*4);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(_pin, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    if(Serial.available())
    {
        char str;
        str = Serial.read();
        morseSendChar(str);
    }
}

void morseSendChar(char chr)
{
    if(chr >= 'a')
    {
        chr = chr - 32;
    }
    switch(chr)
    {
        case 'A':
            dot();
            dash();
        break;
        case 'B':
            dash();
            dot();
            dot();
            dot();
        break;
        case 'C':
            dash();
            dot();
            dash();
            dot();
        break;
        case 'D':
            dash();
            dot();
            dot();
        break;
        case 'E':
            dot();
        break;
        case 'F':
            dot();
            dot();
            dash();
            dash();
            dot();
        break;
        case 'G':
            dash();
            dash();
            dot();
        break;
        case 'H':
            dot();
            dot();
            dot();
            dot();
        break;
        case 'I':
            dot();
            dot();
        break;
        case 'J':
            dot();
            dash();
            dash();
            dash();
        break;
        case 'K':
            dash();
            dot();
            dash();
        break;
        case 'L':
            dot();
            dash();
            dot();
            dot();
        break;
        case 'M':
            dash();
            dash();
        break;
        case 'N':
            dash();
            dot();
        break;
        case 'O':
            dash();
            dash();
            dash();
        break;
        case 'P':
            dot();
            dash();
            dash();
            dot();
        break;
        case 'Q':
            dash();
            dash();
            dot();
            dash();
        break;
        case 'R':
            dot();
            dash();
            dot();
        break;
        case 'S':
            dot();
            dot();
            dot();
        break;
        case 'T':
            dash();
        break;
        case 'U':
            dot();
            dot();
            dash();
        break;
        case 'V':
            dot();
            dot();
            dot();
            dash();
        break;
        case 'W':
            dot();
            dash();
            dash();
        break;
        case 'X':
            dash();
            dot();
            dot();
            dash();
        break;
        case 'Y':
            dash();
            dot();
            dash();
            dash();
        break;
        case 'Z':
            dash();
            dash();
            dot();
            dot();
        break;
    }
}

void morseSendString(String str)
{
    int i;
    if(str[str.length() - 1] == '\n')
    {
        str[str.length() - 1] = '\0';
    }
    for(i = 0; i < str.length(); i++)
    {
        morseSendChar(str[i]);
        if(str[i] == ' ')
        {
            w_space();
        }
        else
        {
            if(i != str.length() - 1)
                c_space();
        }
    }
}