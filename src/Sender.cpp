#include <mpc-rbt-solution/Sender.hpp>

void Sender::Node::run()
{
  while (errno != EINTR) {
    if ((std::chrono::steady_clock::now() - timer_tick) < timer_period) continue;
    timer_tick = std::chrono::steady_clock::now();

    callback();
  }
}

void Sender::Node::onDataTimerTick()
{
  data.frame = "map";
  data.x = 1.23;
  data.y = 4.56;
  data.z = 7.89;

  data.timestamp =
    static_cast<uint64_t>(std::chrono::system_clock::now().time_since_epoch().count());

  Socket::IPFrame frame{
    .port = config.remotePort,
    .address = config.remoteAddress,
  };
  RCLCPP_INFO(logger, "Sending data to host: '%s:%d'", frame.address.c_str(), frame.port);

  RCLCPP_INFO(logger, "\n\tstamp: %ld", data.timestamp);
}
