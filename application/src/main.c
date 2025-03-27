
 #include <zephyr/kernel.h>
 #include <zephyr/device.h>
 #include <zephyr/drivers/sensor.h>
 #include <stdio.h>
 
 void main(void)
 {
     const struct device *dev = DEVICE_DT_GET_ONE(bosch_bmi270);
     struct sensor_value acc[3], gyr[3], step_count;
 
     if (!device_is_ready(dev)) {
         printf("Device %s is not ready\n", dev->name);
         return;
     }
 
     printf("Device %p name is %s\n", dev, dev->name);
 
     /* Infinite loop to fetch sensor data every second */
     while (1) {
         /* Fetch latest data from the sensor */
         if (sensor_sample_fetch(dev) < 0) {
             printf("Sensor sample fetch failed\n");
             continue;
         }
 
         /* Get accelerometer and gyroscope values */
         sensor_channel_get(dev, SENSOR_CHAN_ACCEL_XYZ, acc);
         sensor_channel_get(dev, SENSOR_CHAN_GYRO_XYZ, gyr);
         sensor_channel_get(dev, SENSOR_CHAN_STEP, &step_count);
 
         /* Print values */
         printf("AX: %d.%06d; AY: %d.%06d; AZ: %d.%06d; "
                "GX: %d.%06d; GY: %d.%06d; GZ: %d.%06d; "
                "Steps: %d\n",
                acc[0].val1, acc[0].val2,
                acc[1].val1, acc[1].val2,
                acc[2].val1, acc[2].val2,
                gyr[0].val1, gyr[0].val2,
                gyr[1].val1, gyr[1].val2,
                gyr[2].val1, gyr[2].val2,
                step_count.val1);
 
         /* Sleep for 1 second before fetching again */
         k_sleep(K_SECONDS(1));
     }
 }
 