#include <iostream>
#include "modbus.h"
#include "stdint.h"
//#include <locale.h>




int main()
{
    uint8_t tab_DI[2], tab_DO[2];
    uint16_t tab_reg[64];
    uint16_t tab_V[2];
    modbus_t* ctx;
    int rc, i, retry = 1, DO;
    float f;
    int Num;


    // setlocale(LC_ALL, "Rus");

       //Conect to ADAM-6024D
    ctx = modbus_new_tcp("192.168.22.11", 502);
    if (modbus_connect(ctx) == -1)
    {
        fprintf(stderr, "\nConnection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
    }
    else
    {
        while (1)
        {
            printf("\n\nSelect the operating mode: \n0 - Show registers 40001 - 40010. \n1-Enable/Disable emergency outputs. \n2-Reading digital outputs. \n3-ADC (setting the voltage at the normal output) \n");
            scanf("%d", &Num);
            switch (Num)
            {
            case(0)://Чтение регистров
            {
                rc = modbus_read_registers(ctx, 0, 10, tab_reg);
                if (rc == -1)
                {
                    fprintf(stderr, "%s\n", modbus_strerror(errno));
                    return -1;
                }
                for (i = 0; i < rc; i++)
                {
                    printf("reg[%d]=%d (0x%X)\n", i, tab_reg[i], tab_reg[i]);
                }
                break;
            }
            case(1)://Вкл/Выкл дискретных выходов
            {
                printf("\nStatus discrerte output:\n ");
                for (i = 0; i < 2; i++)
                {
                    printf("\nWrite DO[%d] status ,where 1 == ON / 0 == OFF  :", i);
                    scanf_s("%d", &DO);
                    if (DO == 1)
                    {
                        tab_DO[i] = 0;
                    }
                    if (DO == 0)
                    {
                        tab_DO[i] = 1;
                    }
                    if (DO > 1)
                    {
                        printf("\nIncorrect mode . Try again.DO[%d] status is set to OFF\n", i);
                        tab_DO[i] = 1;
                    }

                }
                rc = modbus_write_bits(ctx, 16, 2, tab_DO);
                if (rc == -1)
                {
                    fprintf(stderr, "%s\n", modbus_strerror(errno));
                    return -1;
                }
                break;
            }
            case(2)://Чтение дискретки
            {
                printf("\nStatus discrete input:\n");
                rc = modbus_read_input_bits(ctx, 0, 2, tab_DI);
                if (rc == -1)
                {
                    fprintf(stderr, "%s\n", modbus_strerror(errno));
                    return -1;
                }
                for (i = 0; i < rc; i++)
                {
                    printf("reg[%d]=%d (0x%X)\n", i, tab_DI[i], tab_DI[i]);
                }

                break;
            }
            case(3)://АЦП(ADC)
            {
                for (i = 0; i < 2; i++)
                {
                    printf("Write Ch-[%d] status(0 - 10V):", i);
                    scanf("%f", &f);
                    tab_V[i] = 409.500409 * f;
                }
                rc = modbus_write_registers(ctx, 10, 2, tab_V);
                if (rc == -1)
                {
                    fprintf(stderr, "%s\n", modbus_strerror(errno));
                    return -1;
                }
                break;
            }
            case(4)://ЦАП(DAC)
            {
                rc = modbus_read_registers(ctx , 0 , 2 tab_reg);
                for (i = 0 ; i<rc ; i++)
                    {
                        
                    }
                break;
            }


            }

        }
    }
}
