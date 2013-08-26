#include "detectedevent.h"



DetectedEvent::DetectedEvent()
{
}

DetectedEvent::DetectedEvent(const DetectedEvent &other)
{
    event_identifier = other.getIdentifier();
    event_message = other.getMessage();
    confidence = other.getConfidence();
}

DetectedEvent::~DetectedEvent()
{
}
