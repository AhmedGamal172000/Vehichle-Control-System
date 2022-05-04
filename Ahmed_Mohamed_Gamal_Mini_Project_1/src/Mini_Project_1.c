/*
 * Project C
 * Ahmed Mohamed Gamal
 * Ain Shams - Junior - Computer
 * Diploma 65
 * Deadline 16/4/2022
*/

#include <stdio.h>
#include <stdlib.h>

char second_input;
char first_input;

int room_temperature=28;
int engine_temperature=100;
char traffic_light='g';
int speed=20;
enum {OFF,ON}AC=OFF,Engine_Temp_Controller=OFF,Engine_state=OFF;


void first_welcome_menu();
void second_sensor_menu();
void engine_temp();
void room_temperature_();
void traffic_light_();
void set_when_30_km_hr();
void sensor_menu();
void display();
void scan_traffic();

int main(void)
{
	for(;;)
	{
		first_welcome_menu();
		if(first_input == 'a' || first_input == 'A')
		{
			sensor_menu();
		}
		else if(first_input == 'b' || first_input == 'B')
		{
			printf("\nTurning Off Vehicle!!!");
			continue;
		}
		else if(first_input == 'c' || first_input =='C')
		{
			printf("Program Ended\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
void sensor_menu()
{

	for(;;)
	{
		second_sensor_menu();
		if(second_input == 'a' || second_input == 'A')
		{
			printf("\nTurning Off Vehicle");
			break;

		}
		else if(second_input == 'b' || second_input == 'B')
		{
			Engine_state =ON;
			traffic_light_();
		}
		else if(second_input == 'c' || second_input =='C')
		{
			Engine_state =ON;
			room_temperature_();

		}
		else if(second_input== 'd' || second_input == 'D')
		{
			Engine_state =ON;
			engine_temp();
		}
		display();
	}
}



void first_welcome_menu()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	printf("\nPlease Enter The Number Of The State You Want\n\na- Turn on the vehicle engine\nb- Turn off the vehicle engine\nc- Quit the system");
	printf("\n\nEnter The Number ->  ");
	scanf(" %c",&first_input);
}
void second_sensor_menu()
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	printf("\nPlease Enter The letter for the Sensor you want\n\na- Turn off the engine\nb- Set the traffic light color\nc- Set the room temperature (Temperature Sensor)\nd- Set the engine temperature (Engine Temperature Sensor)");
	printf("\n\nEnter The Letter ->  ");
	scanf(" %c",&second_input);
}
void engine_temp()
{
	printf("\nEnter the Engine temperature right now -> ");
	scanf(" %d",&engine_temperature);

	if(engine_temperature<100)
	{
		Engine_Temp_Controller = ON;
		engine_temperature = 125;

	}
	else if(engine_temperature>150)
	{
		Engine_Temp_Controller = ON;
		engine_temperature = 125;

	}
	else if(engine_temperature>150)
	{
		Engine_Temp_Controller = OFF;

	}

}
void room_temperature_()
{

	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	printf("\nEnter the room temperature right now : ");
	scanf(" %d",&room_temperature);

	if(room_temperature<10)
	{
		AC = ON;
		room_temperature = 20;

	}
	else if(room_temperature>30)
	{
		AC = ON;
		room_temperature = 20;

	}
	else if(room_temperature>30)
	{
		AC = OFF;

	}
}

void traffic_light_()
{
		setvbuf(stdout,NULL,_IONBF,0);
		setvbuf(stderr,NULL,_IONBF,0);


		printf("\nEnter the traffic light right now G, O or R : ");
		scanf(" %c",&traffic_light);

		if(traffic_light == 'g' || traffic_light=='G')
		{
			Engine_state=ON;
			speed = 100;
		}
		else if(traffic_light=='o' || traffic_light == 'O')
		{
			speed = 30;
			set_when_30_km_hr();
		}
		else if (traffic_light == 'r' || traffic_light == 'R')
		{
			speed = 0;
		}
}
void set_when_30_km_hr()
{
	if(AC == OFF)
	{
		AC = ON;
		room_temperature = room_temperature * (5/4) + 1;
		display();
	}

	if(Engine_Temp_Controller == OFF)
	{
		Engine_Temp_Controller = ON;
		engine_temperature = engine_temperature * (5/4) + 1;
		display();
	}
}

void display()
{

	printf("\nEngine State is : %d",Engine_state);
	printf("\nAC is : %d",AC);
	printf("\nVehicle speed is : %d",speed);
	printf("\nRoom Temperature is : %d",room_temperature);
	printf(" C");
	printf("\nEngine Temperature Controller is : %d",Engine_Temp_Controller);
	printf("\nEngine Temperature is : %d",engine_temperature);
	printf(" C");
}
