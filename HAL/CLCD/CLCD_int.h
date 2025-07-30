

#ifndef HAL_CLCD_CLCD_INT_H_
#define HAL_CLCD_CLCD_INT_H_
//create functios
void CLCD_voidSendEnablePulse();
void CLCD_voidSetHalfPort(u8 Copy_u8Data);
void CLCD_voidWriteData(u8 Copy_u8Data);
void CLCD_voidWriteInst(u8 Copy_u8Inst);
void CLCD_voidInit(void);
void CLCD_voidSendString(const u8 * str ) ;
void CLCD_voidGoToX_Y(u8 Copy_u8_X,u8 Copy_u8_Y);
void CLCD_voidWriteSpecialChar(u8 * Copy_pu8Patarn , u8 Copy_u8PattarnNumber , u8 Copy_u8_X,u8 Copy_u8_Y  );

void CLCD_voidClearDisp();

#endif /* HAL_CLCD_CLCD_INT_H_ */
