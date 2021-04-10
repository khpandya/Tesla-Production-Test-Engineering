/*
 * InitBoard - Austin,TX - 2019
 * 
 * Grove - LED Example
 */

// For more info about melody: http://www.arduino.cc/en/Tutorial/Melody

int bzrPin = 3;     // Grove Buzzer connect to D3


int length = 15;    // the number of notes
char notes[] = "ccggaagffeeddc ";       // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) 
{
    for (long i = 0; i < duration * 1000L; i += tone * 2) 
    {
        digitalWrite(bzrPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(bzrPin, LOW);
        delayMicroseconds(tone);
    }
}

void playNote(char note, int duration) 
{
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) 
    {
        if (names[i] == note) 
        {
            playTone(tones[i], duration);
        }
    }
}

void setup()
{
    pinMode(bzrPin, OUTPUT);
}

void loop() 
{
    for (int i = 0; i < length; i++) 
    {
        if (notes[i] == ' ')
        {
            delay(beats[i] * tempo); // rest
        }
        else
        {
            playNote(notes[i], beats[i] * tempo);
        }

        // pause between notes
        delay(tempo / 2);
    }
}
