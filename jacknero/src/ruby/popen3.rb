require 'open3'

Open3.popen3("echo *"){|stdin, stdout,stderr|
  p stdout.read
  p stderr.read
}
