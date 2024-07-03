/***********************************************************************************************************************
 * Filename:      message.h 
 *
 * Description:   This file contains definition of message.
 *
 * History:       2019-07-26 11:37:10
***********************************************************************************************************************/

#ifndef OAM_MESSAGE_H_
#define OAM_MESSAGE_H_

#include <cstdint>
#include <memory>


namespace comm
{

class Message
{
protected:
   uint32_t senderModuleID_;
   uint32_t receiverModuleID_;
   uint32_t msgCode_;

   void* msg_;

public:
   Message(uint32_t senderModuleID, uint32_t receiverModuleID, uint32_t msgCode, void* msg = nullptr)
      : senderModuleID_(senderModuleID), receiverModuleID_(receiverModuleID), msgCode_(msgCode), msg_(msg) {}
   virtual ~Message()   {}

   uint32_t getSenderModuleID() { return senderModuleID_; }
   uint32_t getReceiverModuleID() { return receiverModuleID_; }
   uint32_t getMsgCode() { return msgCode_; }
   void* getMsg() { return msg_; }
};

typedef std::shared_ptr<Message> MessagePtr;

} // namespace comm

#endif // OAM_MESSAGE_H_
