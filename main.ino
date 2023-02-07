int R1 = A0, R2 = A1, R3 = A2, R4 = A3;   // integer analog variables
int dir = 8, ste = 9, dir2 = 2, ste2 = 3; // integer digital variables
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    // déclaration de l&#39;etat du variable
    // OUTPUTS
    // Les OUTPUTS qui vont controller le 1ér moteur et qui les sortie du 1er driver
    pinMode(ste, OUTPUT); // ste c&#39;est pour la polarisation du coils(notre moteur esthybrid(il pet fonctionner comme un bipolaire ou unipolaire)
    pinMode(dir, OUTPUT); // C&#39;est pour le controlle de direction du 1ér moteur
    // Les OUTPUTS qui vont controller le 1ér moteur et qui les sortie du 1er driver
    pinMode(ste2, OUTPUT); // ste c&#39;est pour la polarisation du coils(notre moteur esthybrid(il pet fonctionner comme un bipolaire ou unipolaire)
    pinMode(dir2, OUTPUT); // C&#39;est pour le controlle de direction du 2éme moteur
    // Les INPUTS (on vas lire leur valeurs)
    pinMode(R1, INPUT);
    pinMode(R2, INPUT);
    pinMode(R3, INPUT);
    pinMode(R4, INPUT);
    void loop()
    {
        // on a utiliser analogRead pour la lecture des valeurs des resistances
        // gauche:pour la photoresistor placé à gauche du panneau solaire
        // droite:pour la photoresistor placé à droite du panneau solaire
        // bas:pour la photoresistor placé à bas du panneau solaire
        // haut:pour la photoresistor placé à haut du panneau solaire
        float
            gauche = analogRead(R3),
            droite = analogRead(R4), haut = analogRead(R1), bas = analogRe ad(R2);
        ;

        // affichage des valeurs des 2 premiers photoresistances
        Serial.print("gauche:");
        Serial.println(gauche);
        delay(100);
        Serial.print("droite:");
        Serial.println(droite);
        delay(100);
        // affichage du 1er difference pour choisir la direction de rotation du moteur
        Serial.print("difference1:");
        Serial.println(gauche - droite);
        delay(100);
        // affichage des valeurs des 2 autres photoresistances
        Serial.print("haut: ");
        Serial.println(haut);
        delay(100);
        Serial.print("bas:");
        Serial.println(bas);
        delay(100);
        // affichage du 1er difference pour choisir la direction de rotation du moteur
        Serial.print("difference2");
        Serial.println(haut - bas);
        delay(100);
        // si le 1er difference est superieur à 20 le 1er moteur va tourner dans la direction des
        // aiguilles de montre(la valeurs & gt; 20 est conclu à partir de la lecture du valeurs desphotoresistance)
        // si le 1er difference est inférieur à 0 le 1er moteur va tourner dans la contre direction
        // des aiguilles de montre(la valeurs & lt; 0 est conclu à partir de la lecture du valeursdes photoresistance)
        if ((haut - bas) > 20)
        {
            digitalWrite(dir2, HIGH);
            for (int x = 0; x < 1; x++)
            {
                // là on fait varier la polarisation entre les coils pour assurer le fonctionnement du
                // moteur(le principe de fonctionnement d & #39; un moteur pas à pas)
                digitalWrite(ste2, HIGH);
                delayMicroseconds(500);
                digitalWrite(ste2, LOW);
                delayMicroseconds(500);
            }
        }
    }else if ((haut - bas) < 0)
    {
        digitalWrite(dir2, LOW);
        for (int x = 0; x & lt; 1; x++)
        {
            // là on fait varier la polarisation entre les coils pour assurer le fonctionnement dumoteur(le principe de fonctionnement d & #39; un moteur pas à pas)
            digitalWrite(ste2, HIGH);
            delayMicroseconds(500);
            digitalWrite(ste2, LOW);
            delayMicroseconds(500);
        }
    }
    // si le 2eme difference est superieur à 20 le 2eme moteur va tourner dans la direction
    // des aiguilles de montre(la valeurs & gt; 20 est conclu à partir de la lecture du valeursdes photoresistance) 
    if ((gauche - droite)> 20)
    {
        digitalWrite(dir, HIGH);

        for (intx = 0;x < 1; x++)
        {
            digitalWrite(ste, HIGH);
            delayMicroseconds(5000);
            digitalWrite(ste, LOW);
            delayMicroseconds(5000);
        }
    }
    // si le 2eme difference est inférieur à 0 le 2eme moteur va tourner dans la contre
    // direction des aiguilles de montre(la valeurs & lt; 0 est conclu à partir de la lecture duvaleurs des photoresistance) 
    else if ((gauche - droite) < 0)
    {
        digitalWrite(dir, LOW);
        for (int x = 0;x < 1; x++)
        {
            digitalWrite(ste, HIGH);
            delayMicroseconds(5000);
            digitalWrite(ste, LOW);
            delayMicroseconds(5000);
        }
    }
}