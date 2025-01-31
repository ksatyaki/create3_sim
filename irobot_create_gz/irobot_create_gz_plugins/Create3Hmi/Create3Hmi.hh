/*
 * Copyright 2021 Clearpath Robotics, Inc.
 * @author Roni Kreinin (rkreinin@clearpathrobotics.com)
 */

#ifndef IROBOT_CREATE_GZ__IROBOT_CREATE_GZ_PLUGINS__CREATE3HMI__CREATE3HMI_HH_
#define IROBOT_CREATE_GZ__IROBOT_CREATE_GZ_PLUGINS__CREATE3HMI__CREATE3HMI_HH_

#include <gz/gui/qt.h>

#include <string>

#include <gz/gui/Plugin.hh>
#include <gz/transport/Node.hh>


namespace gz
{

namespace gui
{

class Create3Hmi : public Plugin
{
  Q_OBJECT

  // \brief Name
  Q_PROPERTY(
    QString name
    READ Namespace
    WRITE SetNamespace
    NOTIFY NamespaceChanged
  )

public:
  /// \brief Constructor
  Create3Hmi();
  /// \brief Destructor
  virtual ~Create3Hmi();
  /// \brief Called by Ignition GUI when plugin is instantiated.
  /// \param[in] _pluginElem XML configuration for this plugin.
  void LoadConfig(const tinyxml2::XMLElement *_pluginElem) override;
  // \brief Get the robot name as a string, for example
  /// '/echo'
  /// \return Name
  Q_INVOKABLE QString Namespace() const;

public slots:
  /// \brief Callback in Qt thread when the robot name changes.
  /// \param[in] _name variable to indicate the robot name to
  /// publish the Button commands.
  void SetNamespace(const QString &_name);

signals:
  /// \brief Notify that robot name has changed
  void NamespaceChanged();

protected slots:
  /// \brief Callback trigged when the button is pressed.
  void OnCreate3Button(const int button);

private:
  gz::transport::Node node_;
  gz::transport::Node::Publisher create3_button_pub_;
  std::string namespace_ = "";
  std::string create3_button_topic_ = "/create3_buttons";
};

}  // namespace gui

}  // namespace gz

#endif  // IROBOT_CREATE_GZ__IROBOT_CREATE_GZ_PLUGINS__CREATE3HMI__CREATE3HMI_HH_
