//main.c

void func1(void *param){
	LCD_ShowString(10,0,260,32,32,(uint8_t*)param); 	
}
void func2(void *param){
	LCD_ShowString(10,40,260,32,32,(uint8_t*)"func2"); 	
}
void func3(void *param){
	LCD_ShowString(10,80,260,32,32,(uint8_t*)"func3"); 	
}
void func4(void *param){
	LCD_ShowString(10,120,260,32,32,(uint8_t*)"func4"); 	
}
void func5(void *param){
	LCD_ShowString(10,160,260,32,32,(uint8_t*)"func5"); 	
}
void func6(void *param){
	LCD_Clear(WHITE);	
}



void main(void){

	//CPOST INIT
	ceventInit();


	//main loop
	for(;;){

		cpostProcess();    	

	}

}

//中断事件 任务处理注册
voidIRQ1(void){
	cpost(func1,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,.param="test");  
}

voidIRQ2(void){
	cpost(func2,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,.delay=1000);  
}
voidIRQ3(void){
	cpost(func6,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,);
	cpost(func3,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,);
	cpost(func2,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,.delay=200);
	cpost(func4,.attrs.flag=CPOST_FLAG_CLEAR_FRONT,.delay=2000); 
}

