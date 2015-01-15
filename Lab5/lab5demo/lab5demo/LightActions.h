void light_fear(void){
	float Left_Light, Right_Light;
	int basespeed = 250;

	LCD_clear();
	LCD_printf("ARGG!!\n");
	LCD_printf("IT BURNS!!\n");
	LCD_printf("IT BURNS US!!\n");

	while(1){
		Left_Light = getLeftLight();
		Right_Light = getRightLight();
		STEPPER_move_rn(STEPPER_BOTH,
				STEPPER_BCK, (Right_Light*basespeed/100), 400,	//Left
				STEPPER_BCK, (Left_Light*basespeed/100), 400);	//Right
		TMRSRVC_delay(100); // 0.1 Sec duration
	}
}

void light_aggression(void){
	float Left_Light, Right_Light;
	int basespeed = 250;

	LCD_clear();
	LCD_printf("RAAAAAA...\n");
	LCD_printf("AAAAAAA...\n");
	LCD_printf("AAAAAAA...\n");
	LCD_printf("AAAWWR\n");

	while(1){
		Left_Light = getLeftLight();
		Right_Light = getRightLight();
		STEPPER_move_rn(STEPPER_BOTH,
				STEPPER_FWD, (Left_Light*basespeed/100), 400,	//Left
				STEPPER_FWD, (Right_Light*basespeed/100), 400);	//Right
		TMRSRVC_delay(100); // 0.1 Sec duration
	}	
}

void light_love(void){
	float Left_Light, Right_Light;
	int basespeed = 250;

	LCD_clear();
	LCD_printf("mmmmmmm...\n");
	LCD_printf("light...\n");

	while(1){
		Left_Light = getLeftLight();
		Right_Light = getRightLight();
		STEPPER_move_rn(STEPPER_BOTH,
				STEPPER_FWD, ((100-Left_Light)*basespeed/100), 400,	//Left
				STEPPER_FWD, ((100-Right_Light)*basespeed/100), 400);	//Right
		TMRSRVC_delay(100); // 0.1 Sec duration
	}
}

void light_explorer(void){
	float Left_Light, Right_Light;
	int basespeed = 250;

	LCD_clear();
	LCD_printf("Find!\n");

	while(1){
		Left_Light = getLeftLight();
		Right_Light = getRightLight();
		STEPPER_move_rn(STEPPER_BOTH,
				STEPPER_FWD, ((100-Right_Light)*basespeed/100), 400,	//Left
				STEPPER_FWD, ((100-Left_Light)*basespeed/100), 400);	//Right
		TMRSRVC_delay(100); // 0.1 Sec duration
	}
}