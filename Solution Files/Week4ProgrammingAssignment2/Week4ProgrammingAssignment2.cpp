//This program is used to calculate the charges for a long-distance phone call.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	const float ZERO_TO_SEVEN = 0.12;			//Cost per minute for phone calls starting between 00:00 and 06:59
	const float SEVEN_TO_ONE = 0.23;			//Cost per minute for phone calls starting between 07:00 and 12:59
	const float ONE_TO_NINETEEN = 0.55;			//Cost per minute for phone calls starting between 13:00 and 19:00
	const float NINETEEN_TO_MIDNIGHT = 0.35;	//Cost per minute for phone calls starting between 19:01 and 23:59
	float startTime;							//The starting time of the phone call, input by the user
	float minuteValue;							//The MM that the user entered
	int callDuration;							//The duration of the call in minutes, input by the user
	float callCharges;							//The charges for the call, calculated based on the start time and duration

	//Get the start time of the call from the user.
	cout << "Please input the start time of your call, in the format HH.MM: ";
	cin >> startTime;

	//Determine the .MM value entered by the user
	minuteValue = startTime - static_cast<int>(startTime);

	//Verify that the start time entered by the user is between 00.00 and 23.59.
	if (startTime < 0 || startTime >= 23.60)
	{
		cout << "Error: invalid input.\n"
			<< "Time entered must be between 00.00 and 23.59.\n";

		//Check to see if the user entered an invalid MM value, as a courtesy.
		if (minuteValue >= 0.60)
		{
			cout << "Additionally, the MM value must not be greater than 59.\n";
		}

			cout << "Reload the program and enter a valid call start time.\n";
	}
	else
	{
		//Verify that the user has not entered a value greater than 59 for MM.
		if (minuteValue >= 0.60)
		{
			cout << "Error: invalid input.\n"
				<< "When entering call start time in the format HH.MM,\n"
				<< "MM cannot be greater than 59.\n"
				<< "Restart the program and try again.";
		}

		//Now, assuming that the user entered a valid start time, continue with the program.
		else
		{
			//Get the duration of the call, in minutes, from the user.
			cout << "Now, enter the call time in minutes: ";
			cin >> callDuration;

			//Verify that the user entered a non-negative input.
			if (callDuration < 0)
			{
				cout << "Error: invalid input.\n"
					<< "Must enter a non-negative call duration.\n"
					<< "Please restart the program and try again.";
			}

			//If the user entered an appropriate call duration, then calculate the charges, based on the start time of the call and its duration.
			else
			{
				//Set the formatting for output.
				cout << fixed << showpoint << setprecision(2);

				if (startTime >= 0 && startTime <= 6.59)
				{
					callCharges = callDuration * ZERO_TO_SEVEN;
					cout << "You will be charged $ " << callCharges << " for your call.\n";
				}
				else if (startTime >= 7 && startTime <= 12.59)
				{
					callCharges = callDuration * SEVEN_TO_ONE;
					cout << "You will be charged $ " << callCharges << " for your call.\n";
				}
				else if (startTime >= 13 && startTime <= 19)
				{
					callCharges = callDuration * ONE_TO_NINETEEN;
					cout << "You will be charged $ " << callCharges << " for your call.\n";
				}
				else if (startTime >= 19.01 && startTime <= 23.60)
				{
					callCharges = callDuration * NINETEEN_TO_MIDNIGHT;
					cout << "You will be charged $ " << callCharges << " for your call.\n";
				}
			}
		}
	}

	cout << endl;
	system("PAUSE");
	return 0;

}