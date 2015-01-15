#define RIGHT_PHOTO ADC_CHAN5
#define LEFT_PHOTO ADC_CHAN6

float ALC(void){ //Ambiant Light Calibrater
	float LeftPhoto, RightPhoto;
	LeftPhoto = getLeftLight(0);
	RightPhoto = getRightLight(0);

	Calibration = (LeftPhoto + RightPhoto)*5/2;

	return Calibration;
}

float getLeftLight(float Calibration){
	float voltage, adj_V;
	ADC_SAMPLE adcsample;
	ADC_set_VREF( ADC_VREF_AVCC );
	ADC_set_channel( LEFT_PHOTO );
	adcsample = ADC_sample();
	voltage = adcsample * (5.0/ 1024.0 );

	if (voltage < Calibration){
		voltage = Calibration;
	}

	adj_V = (voltage - Calibration)/(5 - Calibration);

	return adj_V;
}

// getRightLight() converts ADC voltage to value inverse proportional to left light
float getRightLight(float Calibration){
	float voltage, adj_V;
	ADC_SAMPLE adcsample;
	ADC_set_VREF( ADC_VREF_AVCC );
	ADC_set_channel( RIGHT_PHOTO );
	adcsample = ADC_sample();
	voltage = adcsample * ( 5.0 / 1024 );

	if (voltage < Calibration){
		voltage = Calibration;
	}

	adj_V = (voltage - Calibration)/(5 - Calibration);

	return adj_V;
}
