#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte rows=4;
const byte cols=4;
char keys[rows][cols]= {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[rows] = {7,6,5,4};
byte colPins[cols] = {3,2,1,0};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols);
  
String Usuarios[40][3];
String Usuario="";
String contrasenha="";
int cant_usua=0;
String sald="";

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  Usuario="";
  contrasenha="";
  char election;
  lcd.setCursor(0, 0);
  lcd.print("1.admin?");
  lcd.setCursor(0, 1);
  lcd.print("2.ususario?");
  election=keypad.waitForKey();
  lcd.clear();
  if (election=='1')
  {
    delay(500);
    lcd.setCursor(0, 0);
  	lcd.print("contrasenha?");
    for(int x=0;x!=4;x++)
    {
      election=keypad.waitForKey();
      contrasenha+=election;
      lcd.setCursor(x, 1);
      lcd.print(election);
      delay(400);
    }
    lcd.clear();
    //confirmacion
    if(contrasenha=="ABCD")
    {
      
      
      	contrasenha="";
      	sald="";
    	lcd.setCursor(0, 0);
  		lcd.print("bienbenido");
    	delay(400);
      	lcd.clear();
    	lcd.print("ingrese la CC");
      	for (int x=0;election!='*';x++)
        {
          
          election=keypad.waitForKey();
          if(election=='*')
          {
            break;
          }
          if (is_a_num(election)=='1')
          {
          	Usuario+=election;
          	lcd.setCursor(x, 1);
          	lcd.print(election);
          }
          else
          {
            x--;
          }
        }
      
      
      	lcd.clear();
      	lcd.setCursor(0, 0);
  		lcd.print("ingrese la cont");
    	delay(400);
    	for (int x=0;x<4;x++)
        {
          
          election=keypad.waitForKey();
          contrasenha+=election;
          lcd.setCursor(x, 1);
          lcd.print(election);
          
        }
      
      
      	lcd.clear();
      	lcd.setCursor(0, 0);
  		lcd.print("ingrese el sald");
    	delay(400);
    	for (int x=0;election!='*';x++)
        {
          
          election=keypad.waitForKey();
          if(election=='*')
          {
            break;
          }
          if (is_a_num(election)=='1')
          {
          	sald+=election;
          	lcd.setCursor(x, 1);
          	lcd.print(election);
          }
          else
          {
            x--;
          }
        }
        lcd.clear();
      	lcd.setCursor(0, 0);
  		lcd.print("accion");
      	lcd.setCursor(0, 0);
  		lcd.print("exitosa");
    	delay(900);
      	lcd.clear();
      	Usuarios[0][0]=Usuario;
    	Usuarios[0][1]=contrasenha;
    	Usuarios[0][2]=sald;
      	cant_usua++;
      	
      	
      	
    }
    else
    {
      lcd.setCursor(0, 0);
  	  lcd.print("contrasenha");
      lcd.setCursor(0, 1);
  	  lcd.print("incorrecta");
      delay(1500);
      lcd.clear();
    }
  }
  //usuario
  else if (election=='2')
  {
    int ubicacion;
    lcd.setCursor(0, 0);
    lcd.print("bienvenido");
    delay(400);
    lcd.clear();
    lcd.print("ingrese la CC");
    for (int x=0;election!='*';x++)
        {
          
          election=keypad.waitForKey();
          if(election=='*')
          {
            break;
          }
          if (is_a_num(election)=='1')
          {
          	Usuario+=election;
          	lcd.setCursor(x, 1);
          	lcd.print(election);
          }
          else
          {
            x--;
          }
        }
    delay(400);
    lcd.clear();
    for (ubicacion=0;Usuario!=Usuarios[ubicacion][0];ubicacion++)
    {
      if(Usuario==Usuarios[ubicacion][0])
      {
        break;
      }
      else if(ubicacion==cant_usua-1)
      {
        lcd.setCursor(0, 0);
    	lcd.print("usuario");
        lcd.setCursor(0, 1);
    	lcd.print("inexistente");
    	delay(800);
    	lcd.clear();
      }
    }
      if(Usuario==Usuarios[ubicacion][0])
      {
        lcd.setCursor(0, 0);
  		lcd.print("ingrese la cont");
    	delay(400);
    	for (int x=0;x<4;x++)
        {
          
          election=keypad.waitForKey();
          contrasenha+=election;
          lcd.setCursor(x, 1);
          lcd.print(election);
          
        }
        if (contrasenha==Usuarios[ubicacion][1])
        {
          lcd.setCursor(0, 0);
  		  lcd.print("bienvenido");
    	  delay(400);
      	  lcd.clear();
    	  lcd.print("1.consult sald");
          lcd.setCursor(0, 1);
  		  lcd.print("2.retirar");
          while(election!='1' && election!='2')
          {
          	election=keypad.waitForKey();
          }
          lcd.clear();
          if(election=='1')
          {
            lcd.setCursor(0, 0);
          	lcd.print("su saldo es:");
            lcd.setCursor(0, 1);
  		    lcd.print(Usuarios[ubicacion][2]);
            delay(2000);
            lcd.clear();
            Usuarios[ubicacion][2]=String (Usuarios[ubicacion][2].toInt()-1000);
          }
          else if(election=='2')
          {
            sald="";
          	lcd.setCursor(0, 0);
  			lcd.print("valor a retirar");
    		delay(400);
    		for (int x=0;election!='*';x++)
        	{
          
          		election=keypad.waitForKey();
          		if(election=='*')
          		{
           		  break;
          		}
          		if (is_a_num(election)=='1')
          		{
          			sald+=election;
          			lcd.setCursor(x, 1);
          			lcd.print(election);
          		}
          		else
          		{
            		x--;
          		}
        	}
            Usuarios[ubicacion][2]=String (Usuarios[ubicacion][2].toInt()-sald.toInt());
            lcd.clear();
            lcd.setCursor(0, 0);
          	lcd.print("retiro");
            lcd.setCursor(0, 1);
  		    lcd.print("exitoso");
            delay(1000);
            lcd.clear();
          }
        }
      }
  }
}
  
  
char is_a_num(char n)
{
  if(47<int(n)&&int(n)<58)
  {
    return '1';
  }
  return '0';
}
 