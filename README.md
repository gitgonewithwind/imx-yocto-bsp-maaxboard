
you can find the imx yocto guide pdf file to find the  imx yocto version porting from.
I merged the maaxboard company's kernal and u-boot code into the yocto.


because the maaxboard modified the soc.mk file at u-boot/tools/imx-boot/iMX8M/soc.mk(yocto at imx-mkimage/imx-boot ) it can not  support optee before because of no yocto project. I change back, so It supports now


you can direct to use the below command to generate yocto image (I only generate the tar file, I do not test)
DISTRO=fsl-imx-wayland MACHINE=imx8mqevk source fsl-setup-release.sh -b build
bitbake fsl-image-validation-imx

this yocto tar file is big , I put here:  you can use it
https://drive.google.com/open?id=10_jubYNO5IcaKENQ-ZjP5BTfGVSp81O_


some key porting step I posted here:

https://www.element14.com/community/thread/74755/l/how-can-i-build-an-image-for-the-maaxboard-myself?displayFullThread=true


good luck!


hi

 

 I have successfully merged  maaxboard company's  linux and uboot code into the yocto project.

 some key steps:

  

  1. in freescale yocto guide I use yocto version:(asked from technical supporter)

  ...

  $ mkdir imx-yocto-bsp

  $ cd imx-yocto-bsp

  $ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-sumo -m

  imx-4.14.98-2.0.0_ga.xml

  $ repo sync

  ..

   

   2.the board is imx8mqevk

    

    3. patches kernel DTB using:

     

     em_sbc_imx8m.dts    

     remove the other  dts we do not use. that 's it!

      

      3.directly use maaxboard uboot code

       

       em_sbc_imx8m_defconfig for uboot config

       modify key files

        

        modified:   ../../conf/machine/imx8mqevk.conf         (flash_ddr4_em for uboot image,for dtb, for uboot config ,please change

         

         modified:   ../u-boot/u-boot-imx_2018.03.bb

         modified:   ../../recipes-kernel/linux/linux-imx-src-4.14.98.inc

          

          4. uboot makimage tools;

           

           modified:   imx-mkimage_git.inc  (directly  company's source code in u-boot folder : source/u-boot/tools/imx-boot)

            

some files I modified I put here, you can compare the original files with them.

	modified:   imx/meta-bsp/conf/machine/imx8mqevk.conf
	modified:   imx/meta-bsp/recipes-bsp/imx-mkimage/imx-mkimage_git.inc
	modified:   imx/meta-bsp/recipes-bsp/u-boot/u-boot-imx_2018.03.bb
	modified:   imx/meta-bsp/recipes-kernel/linux/linux-imx-src-4.14.98.inc





	maaxboard company uboot souce code which will be used in yocto ./imx/meta-bsp/recipes-bsp/u-boot/u-boot-imx/u-boot_2018.03._develop_50b1e8d144.tar.gz

	I modified mkimage file which is from maaxboard uboot code u-boot/tools/imx-boot/:

	imx-boot.tar.xz   will be use in yocto



	kernel patch 001-kernel-EMBEST.patch in yocto
	
	
	maaxboard linux kernel souce code which not use in yocto ,only for reference,in yocto we use the patch :001-kernel-EMBEST.patch
