require 'open3'

Open3.popen3("ls"){|stdin, stdout, stderr|
  print stdout.read
  print stderr.read
}
