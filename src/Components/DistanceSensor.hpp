#ifndef DISTANCE_SENSOR_HPP
#define DISTANCE_SENSOR_HPP

class DistanceSensor
{
private:
    /**
     * Data Pin Number
     * Is Both trigger Pin and Echo Pin to save a pin.
     */
    int dataPin;
public:
    DistanceSensor(int IOPinNum);
    ~DistanceSensor();
    /**
     * Measure distance.
     * THREADT: Blocking, 50-200ms
     * @return distance in cm
     */
    int measureDistance();
};

#endif