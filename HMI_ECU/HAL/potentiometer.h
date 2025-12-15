
#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_
#include "../UTILS/std_types.h"
#define POT_PIN             3       /* PE3 */
#define POT_ADC_CHANNEL     0       /* AIN0 */

void POT_Init(void);

uint32_t POT_ReadMapped(uint32_t min, uint32_t max);

#endif /* POTENTIOMETER_H_ */
