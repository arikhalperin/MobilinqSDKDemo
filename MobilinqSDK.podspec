Pod::Spec.new do |s|
  s.name               = "MobilinqSDK"
  s.version            = "1.0.0"
  s.summary            = "iOS video chat SDK based on WebRTC"
  s.homepage           = "http://www.mobilinq.io"
  s.author             = "arik@mobilinq.io"
  s.license            = { :type => "BSD", :file => "LICENSE" }
  s.platform           = :ios, "10.2"
  s.source             = { :git => 'https://github.com/arikhalperin/MobilinqSDKDemo.git', :tag => 'v1.5' }
  s.source_files       = "Lib/*.h"
  s.public_header_files = "Lib/*.h"
  s.preserve_paths     =  "libMobilinqSDK.a","MobilinqSDK.framework"
  s.vendored_libraries =  "libMobilinqSDK.a"
  s.vendored_frameworks = "MobilinqSDK.framework"
  s.requires_arc       = true
  s.frameworks         = "CoreAudio", "AVFoundation", "AudioToolbox", "CFNetwork", 'AVFoundation'
  s.libraries          = "stdc++.6", "icucore", "c++"
end
