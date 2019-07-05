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
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    Serial.begin(9600);
  	digitalWrite(0, 0);
    digitalWrite(1, 0);
    digitalWrite(2, 0);
    digitalWrite(3, 0);
}

void loop() {
    int num;
    // put your main code here, to run repeatedly:
    if(Serial.available() > 0)
    {
        num = Serial.read() - '0';
        digitalWrite(2, numbers[num][3]);
        digitalWrite(3, numbers[num][2]);
        digitalWrite(4, numbers[num][1]);
        digitalWrite(5, numbers[num][0]);
        delay(10);
    }
    
}