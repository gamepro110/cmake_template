// def codechecker() { return "/home/void/codechecker/build/CodeChecker/bin/CodeChecker" }
def BuildFile() { return "codechecker-build-${env.BUILD_NUMBER}.log" }
def GetCMakePresetString() { return "${env.PLATFORM}-${env.COMPILER}-${env.CONFIG}" }
def getBuildCmd() {
	def defaultBuildCmd = "cmake --build --preset=${GetCMakePresetString()}"

	// if ("${env.NODE}" == 'node-ubuntu') {
	// 	return "${codechecker()} log -o 'codechecker-build-${env.BUILD_NUMBER}.log' --b '${defaultBuildCmd}'"
	// }
	// else{
    return "${defaultBuildCmd()}"
	// }
}

pipeline {
	agent none
	stages {
		stage('Matrix Build') {
			matrix {
				axes {
					axis {
						name 'NODE'
						values 'pi-dev', 'pi-dev'//, 'win'//,''
					}
					axis {
						name 'PLATFORM'
						values 'linux'//, 'windows'
					}
					axis {
						name 'COMPILER'
						values 'clang', 'gcc'//, 'msvc'
					}
					axis {
						name 'CONFIG'
						values 'debug'//, 'release', 'dist'
					}
				}
				excludes {
					exclude { // if 'windows' exclude gcc
						axis {
							name 'PLATFORM'
							values 'windows'
						}
						axis {
							name 'COMPILER'
							values 'gcc'
						}
					}
					exclude { // if !'windows' exclude msvc
						axis {
							name 'PLATFORM'
							notValues 'windows'
						}
						axis {
							name 'COMPILER'
							values 'msvc'
						}
					}
				}
				agent {
                    node env.PLATFORM
                }
				stages {
					stage('Configure') {
						steps {
							sh "cmake . --preset=${GetCMakePresetString()}"
						}
					}
                    stage('Build') {
						steps {
							script {
								// if ("${env.NODE}" == 'node-ubuntu') {
									
								// 	def CodeAnalizeCommand = "${codechecker()} analyze ${BuildFile()} -o CodeChecker --skip /home/void/CodeCheckerSkipFile.txt"

								// 	sh "${getBuildCmd()}"
								// 	sh "${CodeAnalizeCommand} || true"
								// 	sh "${codechecker()} store ./${BuildFile()} -n build-${env.BUILD_NUMBER} --name build-${env.BUILD_NUMBER} --tag ${env.BUILD_NUMBER} --url http://192.168.30.61:8001/jenk-test"
								// }
								// else{
                                sh "${getBuildCmd()}"
								// }
							}
						}
                    }
					stage('test') {
                        steps{
                            sh "ctest --preset=${GetCMakePresetString()}"
                        }
                    }
					stage('artifacts') {
						steps{
							archiveArtifacts artifacts: "out/build/${GetCMakePresetString()}/*",
                                fingerprint: true,
                                onlyIfSuccessful: true

						}
					}
					stage('cleanup') {
						steps{
                            sh 'cd out/build'
							deleteDir()
						}
					}
				}
			}
		}
	}
}
