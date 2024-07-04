#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>

// Base class for notifications
class Notification {
public:
    virtual void send(const std::string& content) = 0;
    virtual ~Notification() = default;
};

// Concrete notification classes
class EmailNotification : public Notification {
public:
    void send(const std::string& content) override {
        std::cout << "Sending Email: " << content << std::endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const std::string& content) override {
        std::cout << "Sending SMS: " << content << std::endl;
    }
};

class PushNotification : public Notification {
public:
    void send(const std::string& content) override {
        std::cout << "Sending Push Notification: " << content << std::endl;
    }
};

// Factory for creating notifications
class NotificationFactory {
public:
    static std::unique_ptr<Notification> createNotification(const std::string& type) {
        if (type == "email") return std::make_unique<EmailNotification>();
        if (type == "sms") return std::make_unique<SMSNotification>();
        if (type == "push") return std::make_unique<PushNotification>();
        throw std::invalid_argument("Unknown notification type");
    }
};

// Manager class for handling notifications
class NotificationManager {
private:
    std::vector<std::string> log;
    std::mutex mutex;
    std::unordered_map<std::string, int> priorities{{"email", 1}, {"sms", 2}, {"push", 3}};

public:
    void sendNotification(const std::string& type, const std::string& content) {
        try {
            auto notification = NotificationFactory::createNotification(type);
            notification->send(content);
            
            std::lock_guard<std::mutex> lock(mutex);
            log.push_back("Sent " + type + ": " + content);
        } catch (const std::exception& e) {
            std::cerr << "Error sending notification: " << e.what() << std::endl;
        }
    }

    std::vector<std::string> getNotificationLog() {
        std::lock_guard<std::mutex> lock(mutex);
        return log;
    }

    void sendBatchNotifications(const std::vector<std::pair<std::string, std::string>>& notifications) {
        std::vector<std::pair<std::string, std::string>> sortedNotifications = notifications;
        std::sort(sortedNotifications.begin(), sortedNotifications.end(),
                  [this](const auto& a, const auto& b) {
                      return priorities[a.first] < priorities[b.first];
                  });

        for (const auto& [type, content] : sortedNotifications) {
            sendNotification(type, content);
        }
    }
};

// Main function to demonstrate usage
int main() {
    NotificationManager manager;

    // Send individual notifications
    manager.sendNotification("email", "Hello via email");
    manager.sendNotification("sms", "Hello via SMS");
    manager.sendNotification("push", "Hello via push notification");

    // Send batch notifications
    std::vector<std::pair<std::string, std::string>> batchNotifications = {
        {"push", "Urgent push notification"},
        {"email", "Batch email"},
        {"sms", "Batch SMS"}
    };
    manager.sendBatchNotifications(batchNotifications);

    // Print log
    std::cout << "\nNotification Log:" << std::endl;
    for (const auto& entry : manager.getNotificationLog()) {
        std::cout << entry << std::endl;
    }

    return 0;
}