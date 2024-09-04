#include "userbase.h"

QJsonObject userbase:: toJsonObject()const
{
    QJsonObject obj;
    obj["id"] = id;
    obj["timeuse"] = timeuse;
    obj["pass_time"]=pass_time;
    return obj;
}

 userbase userbase:: fromJsonObject(const QJsonObject &obj) {
    QString id2 = obj.value("id").toString();
    int time = obj.value("timeuse").toInt();
    int pass=obj.value("pass_time").toInt();
    return userbase(id2, time,pass);
}

 int userbase::get_time() const
{
     return timeuse;
}

QString userbase::get_id()const
{
    return id;
}

void userbase::change_time(int time)
{
    timeuse=time;
}

void userbase::add_pass_time()
{
    pass_time++;
}

int userbase::get_pass_time()const
{
    return pass_time;
}

QVector<userbase>  userbase::loadUsersFromJson(const QString& filePath)
{
    QVector<userbase> loadedUsers;

    // 打开JSON文件
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Failed to open JSON file: " << filePath;
        return loadedUsers; // 返回空向量，表示加载失败
    }

    // 读取文件内容并解析为JSON对象
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    // 检查是否为有效的JSON数组（假设用户数据是以数组形式存储）
    if (!jsonDoc.isArray())
    {
        qWarning() << "Invalid JSON format: Expected an array";
        return loadedUsers;
    }

    // 解析JSON数组中的每个元素为User对象并添加到QVector中
    QJsonArray jsonArray = jsonDoc.array();
    for (const QJsonValueRef &userValue : jsonArray)
    {
        if (!userValue.isObject())
        {
            qWarning() << "Invalid JSON object in array";
            continue; // 跳过非对象元素
        }

        QJsonObject userObject = userValue.toObject();

        QString id2 = userObject.value("id").toString();
        int time = userObject.value("timeuse").toInt();
        int pass=userObject.value("pass_time").toInt();

        loadedUsers.push_back(userbase(id2, time,pass));
    }

    return loadedUsers;
}


