int numbers[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 1}
};

void setup() {
    // put your setup code here, to run once:
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int num;
    // put your main code here, to run repeatedly:
    if(Serial.available() > 0)
    {
        num = Serial.read() - '0';
        digitalWrite(0, numbers[num][3]);
        digitalWrite(1, numbers[num][2]);
        digitalWrite(2, numbers[num][1]);
        digitalWrite(3, numbers[num][0]);
        delay(100);
    }
    
}