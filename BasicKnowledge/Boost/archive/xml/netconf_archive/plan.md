

```xml
<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<!DOCTYPE boost_serialization>
<boost_serialization signature="serialization::archive" version="17">
<stru_oi class_id="0" tracking_level="0" version="0">
	<declarations class_id="1" tracking_level="0" version="0">
		<supported_mplane_version>version of 1.1</supported_mplane_version>
		<supported_cusplane_version></supported_cusplane_version>
		<supported_header_mechanisms>
			<count>2</count>
			<item_version>0</item_version>
			<item>1</item>
			<item>123</item>
		</supported_header_mechanisms>
	</declarations>
	<operational_state class_id="3" tracking_level="0" version="0">
		<restart_datetime></restart_datetime>
	</operational_state>
	<clock class_id="4" tracking_level="0" version="0">
		<timezone_utc_offset>156</timezone_utc_offset>
	</clock>
	<re_call_home_no_ssh_timer>116</re_call_home_no_ssh_timer>
</stru_oi>
</boost_serialization>
```

```xml
<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<!DOCTYPE boost_serialization>
<boost_serialization signature="serialization::archive" version="17">
    <data xmlns:wd="urn:ietf:params:xml:ns:netconf:default:1.0">
        <mplane-info xmlns="urn:o-ran:mplane-interfaces:1.0">
            <m-plane-interfaces>
                <m-plane-sub-interfaces>
                    <count>1</count>
                    <item_version>0</item_version>
                    <item>
                        <interface-name>ofp1</interface-name>
                        <sub-interface>1</sub-interface>
                    </item>
                </m-plane-sub-interfaces>
                <m-plane-ssh-ports>
                    <call-home-ssh-port wd:default="true">4334</call-home-ssh-port>
                    <server-ssh-port wd:default="true">830</server-ssh-port>
                </m-plane-ssh-ports>
                <m-plane-server-type>
                    <netconf-client-ip-type>ASSIGN_IP_BY_HAND</netconf-client-ip-type>
                    <netconf-client-ipaddr>
                        <count>2</count>
                        <item_version>0</item_version>
                        <item>
                            <mplane-ipv4>172.21.6.113</mplane-ipv4>
                            <mplane-type>O-RAN-DU</mplane-type>
                            <port>4334</port>
                        </item>
                        <item>
                            <mplane-ipv4>172.21.8.98</mplane-ipv4>
                            <mplane-type>O-RAN-DU</mplane-type>
                        </item>
                    </netconf-client-ipaddr>
                </m-plane-server-type>
            </m-plane-interfaces>
        </mplane-info>
    </data>
</boost_serialization>
```
